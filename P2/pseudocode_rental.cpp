/****************************************************************************
	Harrison Cassar
	ID: 505114980
	Discussion 1F
	TA: Tao Zhou
	
	Project 2 for CS31 with Professor Smallberg
	
	Last Edit: 10/11/2018
	
 	Purpose: Code recieves specified input from user and outputs how much
 	to charge a car rental customer who has rented a car for a certain
	number of days and driven a certain number of miles.

 	Input:
 	-odometer readings at the start and end of the rental
 	-the number of days the car was rented
 	-the customer's name
 	-whether or not the car is a luxury car
 	-the month the rental started

****************************************************************************/

//include of libraries & namespaces

//declaration of input-holding variables

int main()
{
	//INPUT:
		//ask for odometer at start input (assume integer)
		//check if negative; return error if so

		//ask for odometer at end input (assume integer)
		//check if odometer is less than start odometer; return error if so

		//ask for rental days input
		//check if negative; return error if so

		//ask for customer name (must have one character; even one ' ' is okay)
		//check if empty; return error if so

		//ask whether or not rental is a luxury car (y/n)
		//check if not lowercase y or n; return error if so

		//ask for month started rental (1-12, corresponds to Jan.-Dec.)
		//check if number is not an integer between 1 and 12 inclusive

	//IF ERROR:
		//output three hyphens (---) with no spaces
		//respective error message

	//ASSUMING NO ERRORS FROM INPUT FOUND:
		//calculations
		//output three hyphens (---) with no spaces
		//final output line with calculated charge:
			//"The rental charge for <name> is $<cost>.<cost to 2 decimal>"
}
