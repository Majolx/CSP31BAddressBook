////////////////////////////////////////////////////////////////////////////////
//	Class DateType has three private data components ( month, day, and year)
//	all of the type int.  The program has setDate, getMonth, getDay, getYear,
//	printDate, and two constructors.
//		By:		Michael Askew
//		Date:	11/13/2013
////////////////////////////////////////////////////////////////////////////////
#ifndef H_DateType
#define H_DateType
#include <iostream>

using namespace std;

class DateType
{
public:
	void setDate(int month, int day, int year); 
	//Function to set the date.
	//The member variables Month, Day, and Year are set 
	//according to the parameters.
	//Postcondition: Month = month; Day = day;
	//               Year = year

	void getDate(int &month, int &day, int &year); 
	//Fuunction to get the date.
	//getDate function to return values by reference
	//Postcondition:  The values are returned by reference

	int getDay() const;
	//Function to return the day.
    //Postcondition: The value of Day is returned.

	int getMonth() const;
	//Function to return the month.  
	//Postcondition: The value of Month is returned

	int getYear() const;
	//Function to return the year.     
	//Postcondition: The value of Year is returned.

	void printDate() const;
	//Function to print the date in the format: Month/Day/Year

	bool operator==(DateType& rhs) const;

	DateType(int month, int day, int year);
	//defalt constructor

	DateType();
	// constructor
private:
	int month;	// variable to store the month
	int day;	// variable to store the day
	int year;	// variable to store the year
	
	bool isLeapYear();	//check if year is a leap year
};
#endif