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
const int MAX_WORDS_IN_DOCUMENT = MAX_DOCUMENT_CHARACTERS/2;

//required function prototypes
int makeProper(char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[], int nPatterns);
int rate(const char document[], const char word1[][MAX_WORD_LENGTH+1], const char word2[][MAX_WORD_LENGTH+1], const int separation[], int nPatterns);

//additional function prototypes
void remove(int index, int& totalPatterns, char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[]);

//testing processes of coded functions
int main()
{
	const int CANDIDATE_PATTERNS = 12;

	char w1[CANDIDATE_PATTERNS][MAX_WORD_LENGTH + 1] = {
		"cat", "mad", "hello", "mad", "", "deranged", "NEFARIOUS", "half-witted", "robot", "plot", "have", "NeFaRiOuS"
	};

	char w2[CANDIDATE_PATTERNS][MAX_WORD_LENGTH + 1] = {
		"cat", "have", "there", "scientist", "potato", "robot", "PLOT", "assistant", "deranged", "Nefarious", "mad", "pLoT"
	};

	int separation[CANDIDATE_PATTERNS] = { 0,4,-9,1,20,3,0,2,1,0,12,0 };

	int numberOfValidPatterns = makeProper(w1, w2, separation, CANDIDATE_PATTERNS);

	for (int i = 0; i < numberOfValidPatterns; i++)
	{
		cout << w1[i] << ", " << w2[i] << ", " << separation[i] << endl;
	}

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
		int length1 = strlen(word1[i]);
		int length2 = strlen(word2[i]);

		if (separation[i] < 0 || length1 == 0 || length2 == 0)
		{
			remove(i, nPatterns, word1, word2, separation);
			continue;
		}

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

		if (removedItem)
			continue;

		//check if pattern is a repeat
		for (int m = 0; m < i; m++)
		{
			if (strcmp(word1[i],word1[m]) == 0)
			{
				if (strcmp(word2[i],word2[m]) == 0)
				{
					if (separation[i] <= separation[m])
						remove(i, nPatterns, word1, word2, separation);
					else
						remove(m, nPatterns, word1, word2, separation);

					removedItem = true;
					break;
				}
			}

			if (strcmp(word1[i],word2[m]) == 0)
			{
				if (strcmp(word2[i],word1[m]) == 0)
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

		if (removedItem)
			continue;

		//increment i counter when candidate pattern is proper (as it made it through all checks)
		i++;
	}

	return nPatterns;
}

//REMOVE FUNCTION MUST INCLUDE UPDATING OF NPATTERNS -1 &nPatterns
void remove(int index, int& totalPatterns, char word1[][MAX_WORD_LENGTH+1], char word2[][MAX_WORD_LENGTH+1], int separation[])
{
	totalPatterns--;

	//iterate through array past the inputted position, setting previous array element to the next element's value
	for (int i = index; i < totalPatterns; i++)
	{
		strcpy(word1[i],word1[i+1]);
		strcpy(word2[i],word2[i+1]); 
		separation[i] = separation[i + 1];
	}
}

int rate(const char document[], const char word1[][MAX_WORD_LENGTH+1], const char word2[][MAX_WORD_LENGTH+1], const int separation[], int nPatterns)
{
	if (nPatterns <= 0)
		return 0;

	//parse document array into 2D array of c-strings for its words
	char wordsInDocument[MAX_WORDS_IN_DOCUMENT][MAX_DOCUMENT_CHARACTERS];

	//declaring and initializing counting variables
	int i, j = 0, currentWord = 0;

	for (i = 0; document[i] != '\0'; i++)
	{	
		if (isalpha)
		{
			set = toLower;
			j++;
		}

		if (space)
		{
			wordsInDocument[currentWord][j];

			j = 0;
			currentWord++;
		}

		if (not a letter or space)
		{
				ignore
		}
	}


	//make copies of inputted arrays
	char local_word1[nPatterns][MAX_WORD_LENGTH+1];
	char local_word2[nPatterns][MAX_WORD_LENGTH+1];
	int local_separation[nPatterns];

	for (int k=0; k < nPatterns; k++)
	{
		strcpy(local_word1[k], word1[k]);
		strcpy(local_word2[k], word2[k]);
		local_separation[k], separation[k];
	}



	//copy all arrays into local variables
	//set cursor to beginning of local variable copy for "document"
	//repeating
		//copy c-string into temp char array until cursor hits space (append a '\0' to end) (if hitting '\0' before a space, then know at end)
			//for loop, strcmp temp char array to "ith" element of "word1"
				//if match, (set cursor2 to cursor1) and move cursor2 back "separation+2" number of spaces (check for out of boundaries by seeing if cursor2 will ever go < 0, and if so, just set spaces counter to = "separation+2"), and add 1 index to move to beginning of proper word
					//copy c-string into temp char array until cursor hits a space (append a '\0' to end) (if hitting '\0' before a space, then know at end)
						//if cursor2 == cursor1, set spacesCounter to 0 and continue on to next iteration
						//strcmp temp char array to respective element of "word2"
							//if match, +1 to total ratingCount AND remove pattern from list with custom "remove" function
						//if not, re-loop copying of c-string and incrementing counter when cursor hits a space
		//+1 cursor1 at end to be at start of next word


	//check edge cases of "hello   \0" for document

	"document" comparing with "ith" element of "word1"
			//if match, look for second word in pattern from range of "ith word of document - (separation+1)" to "ith word of document + (separation+1)"
			//



	return 1;
}