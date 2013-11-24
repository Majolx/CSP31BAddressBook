#include "ExtPersonType.h"
#include "AddressType.h"
#include "DateType.h"
#include <iostream>
#include <string>

using namespace std;

void ExtPersonType::printAddress() const
{
	PersonType p;

	p.print();
	address.print();
}

void ExtPersonType::printInfo() const
{	
	this->print();
	dob.printDate();
	cout << "Phone Number: " << phoneNumber << endl <<
		"Person Type: " << personStatus << endl;
	address.print();
}

void ExtPersonType::setInfo(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phoneN, string stat)
{
	this->setName(f, l);
	dob.setDate(m, d, y);
	address.setAddress(street, city, state, zipcode);
	phoneNumber = phoneN;
	personStatus = stat;
}

void ExtPersonType::setInfo(string firstName, string lastName, AddressType addressType, DateType dateType, string phoneN, string stat)
{
	string st, city, state, zip;
	int m, d, y;
	PersonType name;

	name.setName(firstName, lastName);
	addressType.getAddress(st, city, state, zip);
	address.setAddress(st, city, state, zip);
	dateType.getDate(m, d, y);
	dob.setDate(m, d, y);
	phoneNumber = phoneN;
	personStatus = stat;
}

ExtPersonType::ExtPersonType(string f, string l, int m, int d, int y, string street, string city, string state, string zipcode, string phoneN, string stat)
{
	this->setName(f, l);
	dob.setDate(m, d, y);
	address.setAddress(street, city, state, zipcode);
	phoneNumber = phoneN;
	personStatus = stat;
}

ExtPersonType::ExtPersonType()
{
}

string ExtPersonType::getStatus() const
{
	return personStatus;
}

AddressType ExtPersonType::getAddress() const
{
	return address;
}

DateType ExtPersonType::getDate() const
{
	return dob;
}

string ExtPersonType::getPhoneNumber() const
{
	return phoneNumber;
}

bool ExtPersonType::operator==(ExtPersonType& rhs) const
{
	return (this->getFirstName() == rhs.getFirstName() &&
			this->getLastName() == rhs.getLastName() &&
			this->getAddress() == rhs.getAddress() &&
			this->getDate() == rhs.getDate() &&
			this->getStatus() == rhs.getStatus() &&
			this->getPhoneNumber() == rhs.getPhoneNumber());
}

bool ExtPersonType::operator!=(ExtPersonType& rhs) const
{
	return !(this->getFirstName() == rhs.getFirstName() &&
			this->getLastName() == rhs.getLastName() &&
			this->getAddress() == rhs.getAddress() &&
			this->getDate() == rhs.getDate() &&
			this->getStatus() == rhs.getStatus() &&
			this->getPhoneNumber() == rhs.getPhoneNumber());
}