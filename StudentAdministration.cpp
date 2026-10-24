// StudentAdministration.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Date.h"
#include "Student.h"

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

void testFacultyNumberValidation()
{
	std::cout << Student::isFacultyNumberValid("0000a0000") << std::endl;
	std::cout << Student::isFacultyNumberValid("00000000") << std::endl;
	std::cout << Student::isFacultyNumberValid("000000000") << std::endl;
}
int main()
{
    //std::cout << "Hello World!\n";
	
	//testDates();

	//testFacultyNumberValidation();
	
	Student stud1("John Doe", "121224155", 4.0, Date(1, 1, 2000));
	stud1.printStudent();
}
