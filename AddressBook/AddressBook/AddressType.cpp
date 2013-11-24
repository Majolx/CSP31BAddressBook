#include <iostream>
#include <string>
#include "AddressType.h"

using namespace std;
	void AddressType::setAddress(string strAddr, string c, string st, string z){
		streetAddress = strAddr;
		city = c;
		state = st;
		zipCode = z;
}

	void AddressType::getAddress(string &streetAddress, string &city, string &state, string &zipCode){
	streetAddress = this->streetAddress;
	city = this->city;
	state = this->state;
	zipCode = this->zipCode;
}

	void AddressType::print()const{
	cout << streetAddress << endl << city << ", " << state << " " << zipCode << endl;
}

	bool AddressType::operator==(AddressType& rhs) const{
	return (this->streetAddress == rhs.streetAddress &&
		    this->city == rhs.city &&
			this->state == rhs.state &&
			this->zipCode == rhs.zipCode);
}

	AddressType::AddressType(){
	streetAddress = "";
	city = "";
	state = "";
	zipCode = "";
}
	AddressType::AddressType(string &streetAddress, string &city, string &state, string &zipCode){
	/*AddressType::AddressType(string strAddr, string c, string st, string z){
	streetAddress = strAddr;
	city = c;
	state = st;
	zipCode = z;}*/
	this->streetAddress = streetAddress;
	this->city = city;
	this->state = state;
	this->zipCode = zipCode;
}