////////////////////////////////////////////////////////////////////////////////
//	Class addressType has four private data components (streetAddress, city, state 
//	and zipCode) all of the type string.  The program has setAddress, getAddress, 
//	printAddress, and two constructors.
//		By:		Michael Askew
//		Date:	11/15/2013
////////////////////////////////////////////////////////////////////////////////
#ifndef H_AddressType
#define H_AddressType
#include <iostream>
#include <string>

using namespace std;

class AddressType
{
public:
	void setAddress(string, string, string, string);
	//Function to set the address.
	//The member variables streetAddress, city, state, and zipCode are set 
	//according to the parameters.
	//Postcondition: streetAddress = strAddr; city = c;
	//state = st; zipCode = z;
	//set member variables streetAddress, city, state, zipCode

	void getAddress(string &streetAddress, string &city, string &state, string &zipCode);
	//Fuunction to get the address, city, state, and zipCode.
	//getAddress function to return values by reference
	//Postcondition:  The values are returned by reference

	void print()const;
	//Function to print the date in the format:
	//streetAddress
	//city, state zipcode

	bool operator==(AddressType& rhs) const;
	//Function to overload the relational operator
	//and return the streetAddress, city, state, and zipCode

	AddressType();
	//constructor

	AddressType(string &streetAddress, string &city, string &state, string &zipCode);
	//defalt constructor

private:
	string streetAddress; // variable to store the streetAddress
	string city; // variable to store the city
	string state; // variable to store the state
	string zipCode; // variable to store the zipcode
};
#endif