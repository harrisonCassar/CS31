#include <iostream>
#include <string>
#include <cassert>
//#include <cmath>
using namespace std;

int appendToAll(string a[], int n, string value);
//Append value to the end of each of the n elements of the array and return n.

int lookup(const string a[], int n, string target);
//Return the position of a string in the array that is equal to target; if there is more than one such string,
//return the smallest position number of such a matching string. Return −1 if there is no such string. As noted
//above, case matters: Do not consider "GReg" to be equal to "gReG".

int positionOfMax(const string a[], int n);
//Return the position of a string in the array such that that string is >= every string in the array. If there
//is more than one such string, return the smallest position number of such a string. Return −1 if the array has
//no interesting elements.

int rotateLeft(string a[], int n, int pos); //without new array
//Eliminate the item at position pos by copying all elements after it one place to the left. Put the item that
//was thus eliminated into the last position of the array. Return the original position of the item that was
//moved to the end.

int countRuns(const string a[], int n);
//Return the number of sequences of one or more consecutive identical items in a.

int flip(string a[], int n); //without new array
//Reverse the order of the elements of the array and return n.

int differ(const string a1[], int n1, const string a2[], int n2);
//Return the position of the first corresponding elements of a1 and a2 that are not equal. n1 is the number of
//interesting elements in a1, and n2 is the number of interesting elements in a2. If the arrays are equal up to
//the point where one or both runs out, return whichever value of n1 and n2 is less than or equal to the other.

int subsequence(const string a1[], int n1, const string a2[], int n2);
//If all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where
//that subsequence begins. If the subsequence appears more than once in a1, return the smallest such beginning
//position in the array. Return −1 if a1 does not contain a2 as a contiguous subsequence. (Consider a sequence of 0
//elements to be a subsequence of any sequence, even one with no elements, starting at position 0.)

int lookupAny(const string a1[], int n1, const string a2[], int n2);
//Return the smallest position in a1 of an element that is equal to any of the n2 elements in a2. Return −1 if no
//element of a1 is equal to any element of a2.

int divide(string a[], int n, string divider); //without new array
//Rearrange the elements of the array so that all the elements whose value is < divider come before all the other
//elements, and all the elements whose value is > divider come after all the other elements. Return the position of
//the first element that, after the rearrangement, is not < divider, or n if there are no such elements.


bool isInvalidSize(int n);
bool isInvalidPosition(int n, int position);

int main()
{
	string people[5] = { "dianne", "fiona", "ed", "xavier", "greg" };
	assert(appendToAll(people,-5,"!!!") == -1);
	assert(appendToAll(people,0,"!!!") == 0);
	assert(appendToAll(people,5,"!!!") == 5);

	string people2[5] = { "dianne", "fiona", "ed", "xavier", "greg" };
	assert(lookup(people2,-5,"ed") == -1); 
	assert(lookup(people2,0,"ed") == -1);
	assert(lookup(people2,5,"ed") == 2);
	assert(lookup(people2,5,"john") == -1); 

	string candidate[6] = { "dianne", "fiona", "gavin", "xavier", "ed", "betty" };
	assert(positionOfMax(candidate,6) == 3);
	assert(positionOfMax(candidate,0) == -1);

	string politician[5] = { "eleni", "dianne", "fiona", "kevin", "gavin" };
	assert(rotateLeft(politician,5,1) == 1);

	string x[9] = {
    "xavier", "betty", "john", "john", "ed", "ed", "ed", "john", "john"}; 
    assert(countRuns(x,9) == 5);

    string folks[6] = { "betty", "john", "", "xavier", "kevin", "dianne" };
    assert(flip(folks,4) == 4); 

    string buddies[6] = { "betty", "john", "", "xavier", "kevin", "dianne" };
	string group[5] = { "betty", "john", "dianne", "", "xavier" };
	assert(differ(buddies,6,group,5) == 2);
	assert(differ(buddies,2,group,1) == 1);

	string names[10] = { "eleni", "gavin", "kevin", "greg", "betty", "fiona" };
	string names1[10] = { "gavin", "kevin", "greg" };

	assert(subsequence(names,6,names1,3) == 1);
	string names2[10] = { "eleni", "greg" };
	assert(subsequence(names,5,names2,2) == -1);

	string ids[10] = { "eleni", "gavin", "kevin", "greg", "betty", "fiona" };
	string set1[10] = { "dianne", "betty", "greg", "gavin" };
	assert(lookupAny(ids,6,set1,4) == 1);
	string set2[10] = { "xavier", "ed" };
	assert(lookupAny(ids,6,set2,2) == -1);

	string candidates[6] = { "dianne", "fiona", "gavin", "xavier", "ed", "betty" };
	assert(divide(candidates,6,"eleni") == 3); 
	string candidate2[4] = { "gavin", "kevin", "fiona", "john" };
	assert(divide(candidate2,4,"john") == 2);

	// Their main routine 
	string h[7] = { "greg", "gavin", "ed", "xavier", "", "eleni", "fiona" };
	assert(lookup(h, 7, "eleni") == 5);
	assert(lookup(h, 7, "ed") == 2);
	assert(lookup(h, 2, "ed") == -1);
	assert(positionOfMax(h, 7) == 3);

	string g[4] = { "greg", "gavin", "fiona", "kevin" };
	assert(differ(h, 4, g, 4) == 2);
	assert(appendToAll(g, 4, "?") == 4 && g[0] == "greg?" && g[3] == "kevin?");
	assert(rotateLeft(g, 4, 1) == 1 && g[1] == "fiona?" && g[3] == "gavin?");

	string e[4] = { "ed", "xavier", "", "eleni" };
	assert(subsequence(h, 7, e, 4) == 2);

	string d[5] = { "gavin", "gavin", "gavin", "xavier", "xavier" };
	assert(countRuns(d, 5) == 2);
	
	string f[3] = { "fiona", "ed", "john" };
	assert(lookupAny(h, 7, f, 3) == 2);
	assert(flip(f, 3) == 3 && f[0] == "john" && f[2] == "fiona");
	
	assert(divide(h, 7, "fiona") == 3);
	
	cout << “Good job\n”;

	return 0;
}

bool isInvalidSize(int n)
{
	if (n < 0)
		return true;
	return false;
}

bool isInvalidPosition(int n, int position)
{
	if (position >= n || position < 0)
		return true;
	return false;
}

//=================================================================================================================

int appendToAll(string a[], int n, string value)
{
	if (isInvalidSize(n))
		return -1;

	for (int i = 0; i < n; i++)
		a[i] = a[i] + value;

	return n;
}

int lookup(const string a[], int n, string target)
{
	if (isInvalidSize(n))
		return -1;

	for (int i = 0; i < n; i++)
		if (a[i] == target)
			return i;

	return -1;
}

int positionOfMax(const string a[], int n)
{
	if (isInvalidSize(n))
		return -1;

	if (n == 0)
		return -1;

	int maxposition = 0;

	string max = a[maxposition];

	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
			maxposition = i;
		}
	}

	return maxposition;
}

int rotateLeft(string a[], int n, int pos) //without new array
{
	if (isInvalidSize(n) || isInvalidPosition(n, pos))
		return -1;

	string temp = a[pos];

	for (int i = pos+1; i < n; i++)
	{
		a[i-1] = a[i]; 
	}

	a[n-1] = temp;

	return pos;
}

int countRuns(const string a[], int n)
{
	if (isInvalidSize(n))
		return -1;

	int runs = 0;

	if (n == 0)
		return runs;

	runs++;

	for (int i = 1; i < n; i++)
	{
		if (a[i] != a[i-1])
			runs++;
	}

	return runs;
}

int flip(string a[], int n) //without new array
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

	return n-1;
}