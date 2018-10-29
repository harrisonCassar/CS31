/****************************************************************************
	Harrison Cassar
	ID: 505114980
	Discussion 1F
	TA: Tao Zhou
	
	Project 3 for CS31 with Professor Smallberg
	
	Last Edit: 10/22/2018
	
 	Purpose: Source code contains two functions definitions; expecting poll
 	data string and 1 party letter; "hasProperSyntax" checks for proper syntax
 	of the two inputs, while "tallySeats" alters an inputted int variable to
 	indicate the number of seats predicted to be won by the inputted party
 	based on the inputted poll data string.

****************************************************************************/

//include of libraries & namespaces

//function prototypes

int main()
{
	//test cases for the implementation of both functions
}

//definition for "bool hasProperSyntax(string <name>)"
bool hasProperSyntax(string pollData)
{
	/*in order for a poll data string to be proper, must:
		-have no spaces
		-be composed of proper state forecasts
			-cannot be empty
			-be composed of proper state code
				-capitalize all letters in string
				-must be two letters (if first --> letter, check second --> letter, run code)
					-use provided code to test for valid uppercase state codes
			-be composed of proper party results (one or two digits followed by party code)
				-potential wrong party results:
					-"R"
					-"01"
					-"32IR" -same as-> "32I" "R"
				-look at first character
					-if digit --> check second character
						-if digit --> check third character
							-if letter --> valid
							-else --> invalid
						-if letter --> valid
						-else --> invalid
					-if letter --> invalid
					-if comma --> end of valid state forecast; increment cursor; repeat checking process
					-else --> invalid
				-repeat from "look at first character" until hitting a comma for the first character
		-state forecasts must be separated by commas (i.e. no two state codes in one state forecast)
		-CAN HAVE ZERO FORECASTS
		-cannot have comma before or after poll data, as STATE FORECASTS CANNOT BE EMPTY
	*/

	/*
	repeatedly until end of string size:
		find start of a state forecast
			check for proper state code
			check for proper party results following state code (until the end of a state forecast)
			if either not proper
				return false
	return true;
	*/
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
}