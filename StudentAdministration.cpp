// StudentAdministration.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Date.h"

void testDates()
{
	Date date1(5, 1, 2026);

	//Test Cases For Date
	date1.setDate(29, 2, 2024); //Valid Leap Year
	date1.setDate(29, 2, 2026); //Invalid Date
	date1.setDate(29, 2, 1900); //Invalid
	date1.setDate(29, 2, 2000); //Valid
	date1.setDate(31, 4, 2026); //Invalid
}

int main()
{
    std::cout << "Hello World!\n";

	testDates();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
