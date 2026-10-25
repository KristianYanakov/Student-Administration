#pragma once
#include <ostream>

// ​Date (Дата): съхранява ден (day), месец (month) и година (year). 
// Валидира календарните дати с оглед на високосните години (делимост на 4, но не на 100, освен ако не се дели на 400), 

static const int MIN_YEAR = 1900;

class Date {
private:
	int day;
	int month;
	int year;

	static constexpr  int DAYS_IN_EACH_MONTH_NON_LEAP[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
public:
	Date();
	Date(int d, int m, int y);

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void printDate() const;

	void setDate(int d, int m, int y);

	bool isLeapYear(int y);
	int getDaysInMonth(int m, int y);
	bool isDateValid(int d, int m, int y);

	static int getCurrentYear();
	static int getCurrentMonth();
	static int getCurrentDay();

	friend std::ostream& operator<<(std::ostream& out, const Date& date);

	~Date();
};
