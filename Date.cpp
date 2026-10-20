#include <iostream>


using std::endl;

class Date {
private:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int d, int m, int y);


	~Date()
	{
		std::cout << "Destructor called for Date: " << day << "/" << month << "/" << year << "\n";
	}
};