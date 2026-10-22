#pragma once

class Date {
private:
	int day;
	int month;
	int year;

	static const int CURRENT_YEAR = 2026;
	static const int MIN_YEAR = 1900;

	static constexpr  int DAYS_IN_EACH_MONTH_NON_LEAP[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	Date();
	Date(int d, int m, int y);

	int getDay();
	int getMonth();
	int getYear();
	void printDate();

	void setDate(int d, int m, int y);

	bool isLeapYear(int y);
	int getDaysInMonth(int m, int y);
	bool isDateValid(int d, int m, int y);

	~Date();
};
