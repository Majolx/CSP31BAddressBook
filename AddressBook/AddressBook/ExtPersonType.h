#ifndef _ExtPersonType_h
#define _ExtPersonType_h

#include "PersonType.h"
#include "AddressType.h"
#include "DateType.h"
#include <iostream>
#include <string>

using namespace std;

class ExtPersonType : public PersonType
{
private:
	string phoneNumber;
	string personStatus;
	AddressType address;
	DateType dob;
public:
	void printAddress() const;
	//call the print function of the PersonType then call the print function of the addressType
	void printInfo() const;
	//functionm to print name, date of birth, phone nummber, person's status, and address
	void setInfo(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phone, string person);
	//function that accepts 11 parameters to set a person's information
	void setInfo(string f, string l, AddressType a, DateType d, string phone, string status);
	//function that accepts 6 parameters to set a person's information
	ExtPersonType(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phone, string person);
	//constructor that accepts 11 parameters
	ExtPersonType();
	//default constructor

	string getStatus() const;
	//funtion that return the personStatus
	AddressType getAddress() const;
	//function to return the object address
	DateType getDate() const;
	//function to return the object dob
	string getPhoneNumber() const;
	//function to return phoneNumber

	bool operator==(ExtPersonType& rhs) const;
	//function to overload operator ==
	bool operator!=(ExtPersonType& rhs) const;
	//function to overload operator ==
};

#endif