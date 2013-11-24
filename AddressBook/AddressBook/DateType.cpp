#include <iostream>
#include "DateType.h"

using namespace std;
DateType::DateType(){
	month = 1;
	day = 1;
	year = 1900;
}
DateType::DateType(int month, int day, int year){
	this->month = month;
	this->day = day;
	this->year = year;
}
void DateType::setDate(int month, int day, int year){
	this->day = day;
	this->month = month;
	this->year = year;
}
int DateType::getDay() const{
	return day;
}
int DateType::getMonth() const{
	return month;
}
int DateType::getYear() const{
	return year;
}
void DateType::getDate(int &month, int &day, int &year){
	this->month = month;
	this->day = day;
	this->year = year;

}

bool DateType::operator==(DateType& rhs) const
{
	return (this->day == rhs.day &&
		    this->month == rhs.month &&
			this->year == rhs.year);
}

void DateType::printDate() const{
	cout << month <<"/" << day << "/" << year << endl;
}
bool DateType::isLeapYear(){
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}