/****************************************************************************
	Harrison Cassar
	ID: 505114980
	Discussion 1F
	TA: Tao Zhou

	Project 5 for CS31 with Professor Smallberg

	Last Edit: 11/11/2018

	Purpose: Code serves to properly format word patterns and identifies the
	rating that a specific document matches with some given set of patterns.

****************************************************************************/

//define statement included to remove certain flags with VS
#define _CRT_SECURE_NO_WARNINGS

//include of libraries & namespaces
#include <iostream>
#include <cstring>
#include <cassert>
#include <cctype>
using namespace std;

//declare global constants
const int MAX_WORD_LENGTH = 20;

//required function prototypes
int makeProper(char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[], int nPatterns);
int rate(const char document[], const char word1[][MAX_WORD_LENGTH+1], const char word2[][MAX_WORD_LENGTH+1], const int separation[], int nPatterns);

//additional function prototypes
void remove(int i, int& totalPatterns, char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[])

//testing processes of coded functions
int main()
{
	return 0;
}

int makeProper(char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[], int nPatterns)
{
	//every word only has letters
	//every word has >= 1 letter
	//lowercase

	//must be removed if no characters or contains non-letter
	
	if (nPatterns <= 0)
		return 0;

	for (int i = 0; i < nPatterns;)
	{
		length1 = strlen(word1[i])
		length2 = strlen(word2[i])

		if (separation[i] < 0 || length1 == 0 || length2 == 0)
		{
			remove(i, nPatterns);
			continue;
		}

		bool removedItem = false;

		//check for invalid characters in word1 and make all lower
		for (int j = 0; j < length1; j++)
		{
			if (!isalpha(word1[i][j]))
			{
				remove(i, nPatterns);
				removedItem = true;
				break;
			}
			
			word1[i][j] = tolower(word1[i][j]); 
		}

		if (removedItem)
			continue;

		//check for invalid characters in word2 and make all lower
		for (int k = 0; k < length2; k++)
		{
			if (!isalpha(word2[i][k]))
			{
				remove(i, nPatterns);
				removedItem = true;
				break;
			}
			
			word2[i][k] = tolower(word2[i][k]); 
		}

		if (removedItem)
			continue;

		//check if pattern is a repeat
		for (int m = 0; m < i; m++)
		{
			if (strcmp(word1[i],word1[m]) == 0)
			{
				if (strcmp(word2[i],word2[m]) == 0)
				{
					remove(i, nPatterns);
					removedItem = true;
					break;
				}
			}

			if (strcmp(word1[i],word2[m]) == 0)
			{
				if (strcmp(word2[i],word1[m]) == 0)
				{
					remove(i, nPatterns);
					removedItem = true;
					break;
				}
			}		
		}

		if (removedItem)
			continue;

		//increment i counter when candidate pattern is proper (as it made it through all checks)
		i++;
	}
}

//REMOVE FUNCTION MUST INCLUDE UPDATING OF NPATTERNS -1 &nPatterns
void remove(int i, int& totalPatterns, char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[])
{
	totalPatterns--;

	//iterate through array past the inputted position, setting previous array element to the next element's value
	for (int index = i; index < totalPatterns; index++)
	{
		strcpy(word1[index],word1[index+1]);
		strcpy(word2[index],word2[index+1]); 
		strcpy(separation[index],separation[index+1]);
	}
}

int rate(const char document[], const char word1[][MAX_WORD_LENGTH+1], const char word2[][MAX_WORD_LENGTH+1], const int separation[], int nPatterns)
{
	
}