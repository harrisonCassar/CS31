/****************************************************************************
	Harrison Cassar
	ID: 505114980
	Discussion 1F
	TA: Tao Zhou

	Project 4 for CS31 with Professor Smallberg

	Last Edit: 11/5/2018

	Purpose: Code contains numerous functions for completing various tasks and
	manipulations with arrays (normal C++ arrays not in the <array> library).

****************************************************************************/

//include of libraries & namespaces
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

//required function prototypes
int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int divide(string a[], int n, string divider);

//additional function prototypes
bool isInvalidSize(int n);
bool isInvalidPosition(int n, int position);

//testing processes of coded functions
int main()
{
	return 0;
}

//Checks to see if the inputted array size is invalid (i.e. negative)
bool isInvalidSize(int n)
{
	if (n < 0)
		return true;
	return false;
}


//Checks to see if the inputted position is invalid (i.e. greater than the inputted array size or negative)
bool isInvalidPosition(int n, int position)
{
	if (position >= n || position < 0)
		return true;
	return false;
}

//=================================================================================================================

//Append value to the end of each of the n elements of the array and return n.
int appendToAll(string a[], int n, string value)
{
	if (isInvalidSize(n))
		return -1;

	for (int i = 0; i < n; i++)
		a[i] = a[i] + value;

	return n;
}

//Return the position of a string in the array that is equal to target; if there is more than one such string,
//return the smallest position number of such a matching string. Return −1 if there is no such string. As noted
//above, case matters: Do not consider "GReg" to be equal to "gReG".
int lookup(const string a[], int n, string target)
{
	if (isInvalidSize(n))
		return -1;

	for (int i = 0; i < n; i++)
		if (a[i] == target)
			return i;

	//if no match found, return error
	return -1;
}

//Return the position of a string in the array such that that string is >= every string in the array. If there
//is more than one such string, return the smallest position number of such a string. Return −1 if the array has
//no interesting elements.
int positionOfMax(const string a[], int n)
{
	if (isInvalidSize(n))
		return -1;

	if (n == 0)
		return -1;

	//default begin at the first element of n (which must be > 0)
	int maxposition = 0;
	string max = a[maxposition];

	//iterate through array
	for (int i = 1; i < n; i++)
	{
		//if greater string value is found, set that to the new max and update position record
		if (max < a[i])
		{
			max = a[i];
			maxposition = i;
		}
	}

	return maxposition;
}

//Eliminate the item at position pos by copying all elements after it one place to the left. Put the item that
//was thus eliminated into the last position of the array. Return the original position of the item that was
//moved to the end.
int rotateLeft(string a[], int n, int pos)
{
	if (isInvalidSize(n) || isInvalidPosition(n, pos))
		return -1;

	string temp = a[pos];

	//iterate through array past the inputted position, setting previous array element to the next element's value
	for (int i = pos+1; i < n; i++)
	{
		a[i-1] = a[i]; 
	}

	//set last element in array to original eliminated element
	a[n-1] = temp;

	return pos;
}

//Return the number of sequences of one or more consecutive identical items in a.
int countRuns(const string a[], int n)
{
	if (isInvalidSize(n))
		return -1;

	int runs = 0;

	if (n == 0)
		return runs;

	runs++;

	//
	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[i-1])
			runs++;
	}

	return runs;
}

//Reverse the order of the elements of the array and return n.
int flip(string a[], int n)
{
	if (isInvalidSize(n))
		return -1;

	// 0 and n-1
	// 1 and n-2
	// 2 and n-3
	// ...
	// each store 0,1,2 into temp, then n-1 into 0, then temp into n-1, then increment (and decrement) both

	string temp;

	for (int i = 0, j = n-1; i < (n/2); i++, j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	return n;
}

//Return the position of the first corresponding elements of a1 and a2 that are not equal. n1 is the number of
//interesting elements in a1, and n2 is the number of interesting elements in a2. If the arrays are equal up to
//the point where one or both runs out, return whichever value of n1 and n2 is less than or equal to the other.
int differ(const string a1[], int n1, const string a2[], int n2)
{
	if (isInvalidSize(n1) || isInvalidSize(n2))
		return -1;

	for (int i = 0; i < n1; i++)
	{
		if (i == n2)
			return n2;

		if (a1[i] != a2[i])
			return i;
	}

	return n1;
}

//If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where
//that subsequence begins. If the subsequence appears more than once in a1, return the smallest such beginning
//position in the array. Return −1 if a1 does not contain a2 as a contiguous subsequence. (Consider a sequence of 0
//elements to be a subsequence of any sequence, even one with no elements, starting at position 0.)
int subsequence(const string a1[], int n1, const string a2[], int n2)
{
	if (isInvalidSize(n1) || isInvalidSize(n2) || n2 > n1)
		return -1;

	if (n2 == 0)
		return 0;

	for (int i = 0; i < n1; i++)
	{
		int candidate_position = i;
		int j = 0;
		for (; a1[candidate_position+j] == a2[j]; j++) //MIGHT NEED LOL --> j < n2 && 
		{
			//if both strings will end on the next iteration, but are still both equal, return the starting position
			if (j+1 == n2)
				return candidate_position;
			
			//if one (and only one if past that last if statement) will end on the next iteration, 
			else if (candidate_position+j+1 == n1)
				return -1;
		}
	}

	return -1;
}

//Return the smallest position in a1 of an element that is equal to any of the n2 elements in a2. Return −1 if no
//element of a1 is equal to any element of a2.
int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
	if (isInvalidSize(n1) || isInvalidSize(n2))
		return -1;

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (a1[i] == a2[j])
				return i;
		}
	}

	return -1;
}

//Rearrange the elements of the array so that all the elements whose value is < divider come before all the other
//elements, and all the elements whose value is > divider come after all the other elements. Return the position of
//the first element that, after the rearrangement, is not < divider, or n if there are no such elements.
int divide(string a[], int n, string divider)
{
	if (isInvalidSize(n))
		return -1;

	if (n == 0)
		return n;

	bool switchPerformed;

	do
	{
		switchPerformed = false;

		for (int i = 0; i < n-1; i++)
		{
			if (a[i] > a[i+1])
			{
				string temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;

				switchPerformed = true;
			}
		}

	} while (switchPerformed);

	for (int i = 0; i < n; i++)
	{
		if (a[i] >= divider)
			return i;
	}

	return n;
}