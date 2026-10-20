#pragma once

class Date {
private:
	int day;
	int month;
	int year;

	const int CURRENT_YEAR = 2026;
	const int MIN_YEAR = 1900;

public:
	Date();
	Date(int d, int m, int y);

	int getDay();
	int getMonth();
	int getYear();

	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);

	bool dateIsValid();

	~Date();
};
