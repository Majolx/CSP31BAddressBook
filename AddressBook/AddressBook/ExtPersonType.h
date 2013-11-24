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
	//call the print function of the PersonType then call the print function of the 
	void printInfo() const;

	void setInfo(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phone, string person);
	void setInfo(string f, string l, AddressType a, DateType d, string phone, string status);
	ExtPersonType(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phone, string person);
	ExtPersonType();

	string getStatus() const;
	AddressType getAddress() const;
	DateType getDate() const;
	string getPhoneNumber() const;

	bool operator==(ExtPersonType& rhs) const;
	bool operator!=(ExtPersonType& rhs) const;
};

#endif