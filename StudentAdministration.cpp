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
	date1.setDate(31, 4, 2028); //Invalid
	date1.setDate(31, 4, 1800); //Invalid
}

void testFacultyNumberValidation()
{
	std::cout << Student::isFacultyNumberValid("0000a0000") << std::endl;
	std::cout << Student::isFacultyNumberValid("00000000") << std::endl;
	std::cout << Student::isFacultyNumberValid("000000000") << std::endl;
}

void testCurrentDate()
{
	std::cout << "Current Year: " << Date::getCurrentYear() << std::endl;
	std::cout << "Current Month: " << Date::getCurrentMonth() << std::endl;
	std::cout << "Current Day: " << Date::getCurrentDay() << std::endl;
}

void testGetAge()
{
	// test - current date 24.10.2026
	Student stud1("John Doe", "121224155", 4.0, Date(1, 1, 2005));
	std::cout << stud1.getAge() << std::endl; // - 21

	stud1.setBirthDate(Date(1, 9, 2005)); // One month before - 21
	std::cout << stud1.getAge() << std::endl;

	stud1.setBirthDate(Date(1, 11, 2005)); // One month ahead - 20
	std::cout << stud1.getAge() << std::endl;

	stud1.setBirthDate(Date(24, 10, 2005)); // Birthday - 21
	std::cout << stud1.getAge() << std::endl;

	stud1.setBirthDate(Date(23, 10, 2005)); // date has passed - 21
	std::cout << stud1.getAge() << std::endl;

	stud1.setBirthDate(Date(25, 10, 2005)); // date has passed - 20
	std::cout << stud1.getAge() << std::endl;
}

void testPredefinedStudentComparisonOperator()
{
	Student s1("Ivan", "123456789", 4.90f, Date(1, 1, 2000));
	Student s2("Maria", "987654321", 5.80f, Date(2, 2, 2001));

	(s1 < s2) ? std::cout << s1.getName() << " has lower grades than " << s2.getName() << std::endl : std::cout << s1.getName() << " has higher grades than " << s2.getName() << std::endl;

	Student s3("Pencho", "123456789", 5.90f, Date(1, 1, 2000));
	Student s4("Alvarez", "987654321", 5.80f, Date(2, 2, 2001));

	(s3 < s4) ? std::cout << s3.getName() << " has lower grades than " << s4.getName() << std::endl : std::cout << s3.getName() << " has higher grades than " << s4.getName() << std::endl;
}
int main()
{
    //std::cout << "Hello World!\n";
	
	//testDates(); 

	//testFacultyNumberValidation();
	
	//testCurrentDate();

	//testGetAge();

	//testPredefinedStudentComparisonOperator();

	//-----------------------------------



	
}
