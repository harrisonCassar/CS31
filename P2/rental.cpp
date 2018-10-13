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
#include <iostream>
#include <string>
using namespace std;

//declaration of input-holding variables
int odometerStart;
int odometerEnd;
int rentalDays;
string customerName;
char luxuryStatus;
int monthNumber;

//declare constants
const double BASE_CHARGE_LUXURY = 61.0;
const double BASE_CHARGE_NONLUXURY = 33.0;
const double MILE_CHARGE_FIRST100 = 0.27;
const double MILE_CHARGE_NEXT300_WINTER = 0.27;
const double MILE_CHARGE_NEXT300_NONWINTER = 0.21;
const double MILE_CHARGE_BEYOND400 = 0.19;

int main()
{
	//ask for odometer at start input (assume integer)
	cout << "Odometer at start: ";
	cin >> odometerStart;
	
	//check if negative; return error if so
	if (odometerStart < 0)
	{
		cout << "---\n" << "The starting odometer reading must be nonnegative.\n";
		return 1;
	}

	//=================================================================================
	
	//ask for odometer at end input (assume integer)
	cout << "Odometer at end: ";
	cin >> odometerEnd;

	//check if odometer is less than start odometer; return error if so
	if (odometerEnd < odometerStart)
	{
		cout << "---\n" << "The final odometer reading must be at least as large as the starting reading.\n";
		return 2;
	}

	//=================================================================================

	//ask for rental days input
	cout << "Rental days: ";
	cin >> rentalDays;

	//check if negative; return error if so
	if (rentalDays < 0)
	{
		cout << "---\n" << "The number of rental days must be positive.\n";
		return 3;
	}
	
	//clear extra newline character out of input stream in preparation for next 'getline' command
	cin.ignore(10000,'\n');
	
	//=================================================================================

	//ask for customer name (must have one character; even one ' ' is okay)
	cout << "Customer name: ";
	getline(cin, customerName);

	//check if empty; return error if so
	if (customerName == "")
	{
		cout << "---\n" << "You must enter a customer name.\n";
		return 4;
	}

	//=================================================================================
	
	//ask whether or not rental is a luxury car (y/n)
	cout << "Luxury car? (y/n): ";
	cin >> luxuryStatus;

	//check if not lowercase y or n; return error if so
	if (luxuryStatus != 'y' && luxuryStatus != 'n')
	{
		cout << "---\n" << "You must enter y or n.\n";
		return 5;
	}

	//=================================================================================

	//ask for month started rental (1-12, corresponds to Jan.-Dec.)
	cout << "Month (1=Jan, 2=Feb, etc.): ";
	cin >> monthNumber;

	//check if number is not an integer between 1 and 12 inclusive
	if (monthNumber < 1 && monthNumber > 12)
	{
		cout << "---\n" << "The month number must be in the range 1 through 12.\n";
		return 6;
	}

	//=================================================================================
	//begin calculations:

	//initialization of variable holding total charge
	double totalCharge = 0.0;

	//determine base "per-day" charge
	if (luxuryStatus = 'y')
		totalCharge += (BASE_CHARGE_LUXURY*rentalDays);
	else
		totalCharge += (BASE_CHARGE_NONLUXURY*rentalDays);

	//determine total miles driven;
	int milesDriven = odometerEnd - odometerStart;

	//determine per-mile charge:
	//determine if total miles are larger than 0-100 mile charge range
	if (milesDriven > 100)
	{
		//add charge for first 100 miles
		totalCharge += 100*MILE_CHARGE_FIRST100;

		//remove 100 miles already accounted for
		milesDriven -= 100;

		//determine if remaining miles are larger than next 300 mile charge range (total miles -> 101-400)
		if (milesDriven > 300)
		{
			//add corresponding charge for next 300 miles depending on whether the rental month is during winter or not
			if (monthNumber == 12 || (monthNumber >= 1 && monthNumber <= 3))
				totalCharge += 300*MILE_CHARGE_NEXT300_WINTER;
			else
				totalCharge += 300*MILE_CHARGE_NEXT300_NONWINTER;

			//remove 300 miles already accounted for
			milesDriven -= 300;

			//add charge for rest of the miles driven (beyond 400)
			totalCharge += milesDriven*MILE_CHARGE_BEYOND400;
		}
		//total miles travelled must end in 101-400 range
		else
		{
			//add corresponding charge for rest of miles depending on whether the rental month is during winter or not
			if (monthNumber == 12 || (monthNumber >= 1 && monthNumber <= 3))
				totalCharge += milesDriven*MILE_CHARGE_NEXT300_WINTER;
			else
				totalCharge += milesDriven*MILE_CHARGE_NEXT300_NONWINTER;
		}
	}
	//total miles travelled must end in 0-100 range
	else
	{
		//add charge for total miles driven
		totalCharge += milesDriven*MILE_CHARGE_FIRST100;
	}

	//==============================================================================================================

	//properly format output
	cout.setf(ios::fixed);
	cout.precision(2);

	//output final calculated charge message
	cout << "---\n" << "The rental charge for " << customerName << " is $" << totalCharge;

	//return success and end program
	return 0;
}
