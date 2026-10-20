#include <iostream>
#include "Date.h"

Date::~Date()
{
	std::cout << "Destructor called for Date: " << this->day << "/" << this->month << "/" << this->year << std::endl;
}

//Constructors 
Date::Date() 
{
	this->day = 1;
	this->month = 1;
	this->year = 2000;
}

Date::Date(int d, int m, int y)
{
	this->day = d;
	this->month = m;
	this->year = y;
}

// Getters
int Date::getDay()
{
	return this->day;
}

int Date::getMonth()
{
	return this->month;
}

int Date::getYear()
{
	return this->year;
}

//Setters
void Date::setDay(int d)
{
	// Validate the day value but also check if month is february of a leap year !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	if (d < 1 || d > 31) {
		std::cerr << "Invalid day: " << d << ". Day must be between 1 and 31." << std::endl;
		return;

	}
	this->day = d;
	std::cout << "Day set to: " << this->day << std::endl;
}

void Date::setMonth(int m) 
{
	if (m < 1 || m > 12)
	{
		std::cerr << "Invalid month: " << m << ". Month must be between 1 and 12." << std::endl;
		return;
	}
	this->month = m;
	std::cout << "Month set to: " << this->month << std::endl;
}

void Date::setYear(int y)
{
	if(y < this->MIN_YEAR || y > this->CURRENT_YEAR)
	{
		std::cerr << "Invalid year: " << y << ". Year must be between "<< this->MIN_YEAR << " and " << this->CURRENT_YEAR << "." << std::endl;
		return;
	}
	this->year = y;
	std::cout << "Year set to: " << this->year << std::endl;
}