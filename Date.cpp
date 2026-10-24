#include <iostream>
#include <chrono>

#include "Date.h"

Date::Date() 
{
	this->day = 1;
	this->month = 1;
	this->year = 2000;
}

Date::Date(int d, int m, int y)
{	
	if (this->isDateValid(d, m, y))
	{
		this->setDate(d, m, y);
		return;
	}

	std::cerr << "Error: Invalid Date entered!\nFalling back to default date 1/1/2000\n" << std::endl;
	this->day = 1;
	this->month = 1;
	this->year = 2000;
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

void Date::printDate()
{
	std::cout << "DATE : " << this->getDay() << "/" << this->getMonth() << "/" << this->getYear() << "\n" << std::endl;
}

// Setter
//combine in 1 setter to avoid setter order trap of having to validate each time and maybe on first entry day is find but then we change smth and year is leap etc.

void Date::setDate(int d, int m, int y)
{
	if (this->isDateValid(d, m, y))
	{
		this->day = d;
		this->month = m;
		this->year = y;

		//this->printDate();
		return;
	}
	std::cerr << "Error: Invalid Date entered! " << d << " " << m << " " << y << "\n" << std::endl;
}

// Helpers

bool Date::isLeapYear(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) 
		|| y % 400 == 0)
	{
		return true;
	}
	return false;
}

int Date::getDaysInMonth(int m, int y)
{
	if (isLeapYear(y) && m == 2)
	{
		return this->DAYS_IN_EACH_MONTH_NON_LEAP[m - 1] + 1;
	}
	return this->DAYS_IN_EACH_MONTH_NON_LEAP[m - 1];
}


bool Date::isDateValid(int d, int m, int y)
{
	if (y < MIN_YEAR || y > Date::getCurrentYear() ||
		m < 1 || m > 12 || 
		d < 1 || d > this->getDaysInMonth(m, y))
	{
		return false;
	}

	return true;
}

int Date::getCurrentYear()
{
	// Get current time
	auto const now = std::chrono::system_clock::now();

	// Convert to year_month_day
	auto const ymd = std::chrono::year_month_day{ std::chrono::floor<std::chrono::days>(now) };

	// Extract as integers
	int year = static_cast<int>(ymd.year());
	return year;


}

int Date::getCurrentMonth()
{
	// Get current time
	auto const now = std::chrono::system_clock::now();

	// Convert to year_month_day
	auto const ymd = std::chrono::year_month_day{ std::chrono::floor<std::chrono::days>(now) };

	// Extract as integers
	unsigned int month = static_cast<unsigned int>(ymd.month());

	return month;
}

int Date::getCurrentDay()
{
	// Get current time
	auto const now = std::chrono::system_clock::now();

	// Convert to year_month_day
	auto const ymd = std::chrono::year_month_day{ std::chrono::floor<std::chrono::days>(now) };

	// Extract as integers
	unsigned int day = static_cast<unsigned int>(ymd.day());

	return day;

}

Date::~Date()
{
	//std::cout << "Destructor called for Date: " << std::endl;
	//this->printDate();
}