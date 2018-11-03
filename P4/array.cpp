#include <iostream>
#include <string>
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


bool isInvalidLength(int n);

int main()
{
	return 0;
}

bool isInvalidLength(int n)
{
	if (n < 0)
		return true
	return false
}

int appendToAll(string a[], int n, string value)
{
	for (int i = 0; i < n; i++)
		a[i] = a[i] + value;
	return n;
}