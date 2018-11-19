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
const int MAX_DOCUMENT_CHARACTERS = 250;
const int MAX_WORDS_IN_DOCUMENT = MAX_DOCUMENT_CHARACTERS / 2;

//required function prototypes
int makeProper(char word1[][MAX_WORD_LENGTH + 1], char word2[][MAX_WORD_LENGTH + 1], int separation[], int nPatterns);
int rate(const char document[], const char word1[][MAX_WORD_LENGTH + 1], const char word2[][MAX_WORD_LENGTH + 1], const int separation[], int nPatterns);

//additional function prototypes
void remove(int index, int& totalPatterns, char word1[][MAX_WORD_LENGTH + 1], char word2[][MAX_WORD_LENGTH + 1], int separation[]);

//testing processes of coded functions
int main()
{
	//makeProper Testing 
	const int NUM_PATTERNS = 8; 
	// Sample Test Case 
	char list1[NUM_PATTERNS][MAX_WORD_LENGTH + 1] = {
		"mad","deranged","NEFARIOUS","half-witted","robot","plot","have","NeFaRiOuS"
	};
	char list2[NUM_PATTERNS][MAX_WORD_LENGTH + 1] = {
		"scientist","robot","PLOT","assistant","deranged","Nefarious","mad","pLoT"
	};
	int distance[NUM_PATTERNS] = {1,3,0,2,1,0,12,0}; 

	assert(makeProper(list1,list2,distance,NUM_PATTERNS) == 4); 

	cout << "You aight" << endl;
	//rate Testing
	const int TEST1_NRULES = 4;
            char test1w1[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
                "mad",       "deranged", "nefarious", "have"
            };
            char test1w2[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
                "scientist", "robot",    "plot",      "mad"
            };
            int test1dist[TEST1_NRULES] = {
                1,           3,          0,           12
            };
           int num  = 0; 
           assert(rate("The mad UCLA scientist unleashed a deranged evil giant robot.",
			test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
           num++; 
           assert(rate("The mad UCLA scientist unleashed    a deranged robot.",
			test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
           num++; 
            assert(rate("**** 2018 ****",
			test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
			num++; 
            assert(rate("  That plot: NEFARIOUS!",
			test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
			num++;
            assert(rate("deranged deranged robot deranged robot robot",
			test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
			num++; 
			int x = rate("That scientist said two mad scientists suffer from deranged-robot fever.",
			test1w1, test1w2, test1dist, TEST1_NRULES); 
			
            assert(rate("That scientist said two mad scientists suffer from deranged-robot fever.",
			test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
			num++; 

			for(int b = 1; b <= num; b++){
				cout << "Test case " << b << " PASSED" << endl;
			}

    	cout << "Who's that with the amazing code? YOU! Wow, great comments and those codes are on the spot!" << endl;


}

//takes in inputted candidate patterns and alters the arrays to only have proper, non-repeating patterns, returning the number of proper patterns
int makeProper(char word1[][MAX_WORD_LENGTH + 1], char word2[][MAX_WORD_LENGTH + 1], int separation[], int nPatterns)
{
	//check for negative or 0 for indicated number of patterns
	if (nPatterns <= 0)
		return 0;

	//loop through all pattern sets inputted
	for (int i = 0; i < nPatterns;)
	{
		//check for negative separation values and 0 length for words for focused pattern
		int length1 = strlen(word1[i]);
		int length2 = strlen(word2[i]);
		if (separation[i] < 0 || length1 == 0 || length2 == 0)
		{
			remove(i, nPatterns, word1, word2, separation);
			continue;
		}

		//declare boolean, intialized to false for checking if pattern was removed
		bool removedItem = false;

		//check for invalid characters in word1 and make all lower
		for (int j = 0; j < length1; j++)
		{
			if (!isalpha(word1[i][j]))
			{
				remove(i, nPatterns, word1, word2, separation);
				removedItem = true;
				break;
			}

			word1[i][j] = tolower(word1[i][j]);
		}

		//check to see if pattern is already determined invalid and was removed
		if (removedItem)
			continue;

		//check for invalid characters in word2 and make all lower
		for (int k = 0; k < length2; k++)
		{
			if (!isalpha(word2[i][k]))
			{
				remove(i, nPatterns, word1, word2, separation);
				removedItem = true;
				break;
			}

			word2[i][k] = tolower(word2[i][k]);
		}

		//check to see if pattern is already determined invalid and was removed
		if (removedItem)
			continue;

		//check if pattern is a repeat
		for (int m = 0; m < i; m++)
		{
			//check if word1 of current pattern is equal to word1 of any past patterns
			if (strcmp(word1[i], word1[m]) == 0)
			{
				if (strcmp(word2[i], word2[m]) == 0)
				{
					if (separation[i] <= separation[m])
						remove(i, nPatterns, word1, word2, separation);
					else
						remove(m, nPatterns, word1, word2, separation);

					removedItem = true;
					break;
				}
			}

			//check if word1 of current pattern is equal to word2 of any past patterns
			if (strcmp(word1[i], word2[m]) == 0)
			{
				if (strcmp(word2[i], word1[m]) == 0)
				{
					if (separation[i] <= separation[m])
						remove(i, nPatterns, word1, word2, separation);
					else
						remove(m, nPatterns, word1, word2, separation);

					removedItem = true;
					break;
				}
			}
		}

		//check to see if pattern is already determined invalid and was removed
		if (removedItem)
			continue;

		//increment i counter when candidate pattern is proper (as it made it through all checks)
		i++;
	}

	//return final number of proper patterns (nPatterns is modified by "remove" function)
	return nPatterns;
}

//remove function utilized in "makeProper" function above for removing and properly adjusting arrays and nPatterns variable
void remove(int index, int& totalPatterns, char word1[][MAX_WORD_LENGTH + 1], char word2[][MAX_WORD_LENGTH + 1], int separation[])
{
	totalPatterns--;

	//iterate through array past the inputted position, setting previous array element to the next element's value
	for (int i = index; i < totalPatterns; i++)
	{
		strcpy(word1[i], word1[i + 1]);
		strcpy(word2[i], word2[i + 1]);
		separation[i] = separation[i + 1];
	}
}

//takes in document c-string and arrays of patterns in proper form and returns the number of patterns that have a match in the document c-string
int rate(const char document[], const char word1[][MAX_WORD_LENGTH + 1], const char word2[][MAX_WORD_LENGTH + 1], const int separation[], int nPatterns)
{
	//treat all negative nPatterns as 0 (return 0 instantly)
	if (nPatterns <= 0)
		return 0;

	//parse document c-string into 2D array of c-strings for its words
	char wordsInDocument[MAX_WORDS_IN_DOCUMENT][MAX_DOCUMENT_CHARACTERS];

	//declaring and initializing counting variables
	int i, j = 0, currentWord = 0;

	//iterate through document c-string to make a copy of each word into separate array element
	for (i = 0; document[i] != '\0'; i++)
	{
		if (document[i] == ' ')
		{
			if (document[i+1] == '\0')
				break;
			if (document[i+1] == ' ')
				continue;
			
			wordsInDocument[currentWord][j] = '\0';

			//reset parsed words' character counter and incremented word counter
			j = 0;
			currentWord++;
		}
		else if (isalpha(document[i]))
		{
			wordsInDocument[currentWord][j] = tolower(document[i]);
			j++;
		}
	}

	//append on to end of copy a zerobyte for the last element
	wordsInDocument[currentWord][j] = '\0';

	//declare counting variables for actual determining of totalRating
	int totalRating = 0;
	int separationMinIndex;
	int separationMaxIndex;

	//iterate through word1 patterns array
	for (int candidatePattern = 0; candidatePattern < nPatterns; candidatePattern++)
	{
		bool patternMatch = false;

		//iterate through copied words from document array
		for (int cursor = 0; cursor <= currentWord && (patternMatch == false); cursor++)
		{
			if (strcmp(wordsInDocument[cursor], word1[candidatePattern]) == 0)
			{
				//calculate min and max index relative to current cursor position that found match
				separationMinIndex = cursor - (separation[candidatePattern] + 1);
				separationMaxIndex = cursor + (separation[candidatePattern] + 1);

				//adjust min and max index range values to ensure not stepping over array boundaries
				if (separationMinIndex < 0)
					separationMinIndex = 0;
				if (separationMaxIndex > currentWord) //if max index is greater than the biggest index in the wordsInDocument array, set it to that max
					separationMaxIndex = currentWord;

				for (int j = separationMinIndex; j <= separationMaxIndex; j++)
				{
					//skip over initial word so that patterns with identical word1 and word2 are considered correctly
					if (j == cursor)
						continue;

					//if 2nd respective word matching too, increment totalRating counter by 1 and indicate pattern has been found
					if (strcmp(wordsInDocument[j], word2[candidatePattern]) == 0)
					{
						patternMatch = true;
						totalRating++;
						break;
					}
				}
			}
		}
	}

	//return totalRating after incrementation
	return totalRating;
}