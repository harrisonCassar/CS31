/****************************************************************************
	Harrison Cassar
	ID: 505114980
	Discussion 1F
	TA: Tao Zhou
	
	Project 3 for CS31 with Professor Smallberg
	
	Last Edit: 10/24/2018
	
 	Purpose: Source code contains two functions definitions; expecting poll
 	data string and 1 party letter; "hasProperSyntax" checks for proper syntax
 	of the two inputs, while "tallySeats" alters an inputted int variable to
 	indicate the number of seats predicted to be won by the inputted party
 	based on the inputted poll data string.

****************************************************************************/

//include of libraries & namespaces
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//function prototypes
bool hasProperSyntax(string pollData);
int tallySeats(string pollData, char party, int &seatTally);
bool isValidUppercaseStateCode(string stateCode);

int main()
{
	//test cases for the implementation of both functions
}

//definition for "bool hasProperSyntax(string <name>)"
bool hasProperSyntax(string pollData)
{
	//check for extreme short pollData strings (0 is always VALID, 1 is always INVALID)
	if (pollData.size() == 0)
		return true;
	else if (pollData.size() == 1)
		return false;

	//capitalize all letters of string to make letter detection easier (not case-sensitive)
	for (int i = 0; i < pollData.size(); i++)
	{
		pollData[i] = toupper(pollData[i]);
	}

	//set cursor to start of the (supposed) first state forecast
	unsigned int cursor = 0;

	//enter loop, iterating and checking all state forecasts separated by commas
	while (true)
	{
		//if first two characters are letters, check if they encode for a valid state code
		string candidateStateCode = "";
		if (isalpha(pollData[cursor]) && isalpha(pollData[cursor+1])) //CHECK to see if this good with a "<letter><party symbol without numbers>"
		{
			candidateStateCode += pollData[cursor] + pollData[cursor+1];
			if (!isValidUppercaseStateCode(candidateStateCode))
			{
				return false;
			}
		}
		else
			return false;

		//move cursor past state code to the start of where party results should be
		cursor += 2;

		//check to make sure cursor is not out of bounds for string
		if (cursor >= pollData.size())
			break;

		//enter loop to check all party results (until end of state forecast is found, as indicated by a comma)
		while (true)
		{
			//check first character (only possible valid in 1st position: digit) (comma already accounted for in while condition)
			if (isdigit(pollData[cursor]))
			{
				//check second character (only two valid in 2nd position: digit or letter)
				
				//if end of string, improper termination of party result (INVALID)
				if (cursor+1 >= pollData.size())
					return false;

				if (isdigit(pollData[cursor+1]))
				{
					//check third character (only one valid in 3rd position: letter)
					
					//if end of string, improper termination of party result (INVALID)
					if (cursor+2 >= pollData.size())
						return false;

					if (isalpha(pollData[cursor+2]))
						cursor += 3;
					else
						return false;
				}
				else if (isalpha(pollData[cursor+1]))
					cursor +=2;
				else
					return false;
			}
			else if (pollData[cursor] == ',')
			{
				//increment cursor
				cursor++;

				//check to make sure cursor is not at end of string (if so, INVALID, as at least two characters must follow comma for a valid pollData string)
				if (cursor+1 >= pollData.size())
					return false;

				//break out of loop, as end of state forecast has been found
				break;
			}
			else
				return false;

			//check to make sure cursor is not out of bounds for string
			if (cursor >= pollData.size())
				break;
		}

		//move cursor past ended state forcaststate code to the start of where party results should be
	}
	
	//if no errors found previously, must be valid
	return true;
}

//definition for "int tallySeats(string <name>, char <name>, int& <name>)"
int tallySeats(string pollData, char party, int &seatTally)
{
	/*
	check pollData string is proper
		return 1 if not
	check party character is proper (a letter)
		return 2 if not

	set seatTally to 0 to start with
	capitalize string and copy of party completely

	find party result in state forecast
		-move two characters forward
		-iterate through string until character matches party
			-if party character, read 2 characters back
				-if letter --> read 1 character back --> add to seatTally
				-if number --> add to seatTally
		-increment counter variable, and continue iterating through (repeat)
	*/

	//check to make sure both data inputs are valid
	if (!hasProperSyntax(pollData))
		return 1;
	if (!isalpha(party))
		return 2;

	//reset seatTally to 0 so we can ensure
	seatTally = 0;

	//capitalize both inputs to make letter detection easier (not case-sensitive)
	char capitalizedparty = toupper(party);

	for (int i = 0; i != pollData.size(); i++)
	{
		pollData[i] = toupper(pollData[i]);
	}

	//iterate through string until inputted party found inside pollData string, then add seat prediction value (its preceding value) to seatTally

	//iterate through state forecasts
	for (unsigned int i = 0; i < pollData.size(); i++)
	{
		//skip over state code
		i += 2;

		//check for out of bounds
		if (i >= pollData.size())
			break;

		//iterate through characters within a state forecast
		while (true)
		{
			//if at end of state forecast, move to next one
			if (pollData[i] == ',')
			{
				i++;
				break;
			}

			//if party match is found, add digits preceding it to tally
			if (pollData[i] == capitalizedparty)
			{
				seatTally += (pollData[i-1]-'0');

				if (isdigit(pollData[i-2]))
					seatTally += (10*(pollData[i-1]-'0'));
			}

			i++;

			//check if out of bounds (i.e. in the case of "CA3R") to avoid segmentation fault
			if (i >= pollData.size())
				break;
		}
	}

	return 0;
	/*
	check if pollData string is proper
		return 1 if not
	check if party character is proper (a letter)
		return 2 if not
	
	reset total tally value to 0

	repeating until end of data string
		iterate through string until find indicated party inside pollData string
			add party result to total tally
	
	return 0 for success
	*/

	//change seatTally
	//return 0 for success

	//MAKE SURE TO RETURN TALLY SEATS TO THE CORRECT CAPITALIZATION OF PARTYYY!!!
	//in other words, DO NOT CAPITALIZE INPUT! only capitalize a copy of the input!

	return 0;
}

bool isValidUppercaseStateCode(string stateCode)
{
    const string codes =
        "AL.AK.AZ.AR.CA.CO.CT.DE.FL.GA.HI.ID.IL.IN.IA.KS.KY."
        "LA.ME.MD.MA.MI.MN.MS.MO.MT.NE.NV.NH.NJ.NM.NY.NC.ND."
        "OH.OK.OR.PA.RI.SC.SD.TN.TX.UT.VT.VA.WA.WV.WI.WY";
    return (stateCode.size() == 2  &&
            stateCode.find('.') == string::npos  &&  // no '.' in stateCode
            codes.find(stateCode) != string::npos);  // match found
}