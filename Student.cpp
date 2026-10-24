#include <iostream>
#include <string>
#include <regex>

#include "Date.h"
#include "Student.h"


Student::Student()
{
	this->name = "Kristian Yanakov";
	this->faculty_number = "121224148";
	this->average_gpa = 5.84f;
	this->birth_date = Date(3, 7, 2005);
}

Student::Student(std::string name, std::string fac_num, float avg_gpa, Date birthday)
{
	this->setName(name);
	this->setFacultyNumber(fac_num);
	this->setAvgGPA(avg_gpa);
	this->setBirthDate(birthday);
}

//Getters

std::string Student::getName()
{
	return this->name;
}

std::string Student::getFacultyNumber()
{
	return this->faculty_number;
}

float Student::getAverageGPA()
{
	return this->average_gpa;
}

Date Student::getBirthDate()
{
	return this->birth_date;
}

//Setters

void Student::setName(std::string name)
{
	this->name = name;
}

void Student::setFacultyNumber(std::string fac_num)
{
	if (isFacultyNumberValid(fac_num))
	{
		this->faculty_number = fac_num;
		return;
	}
	std::cerr << "Invalud facutly number!" << std::endl;
}

void Student::setAvgGPA(float avg_gpa)
{
	if (avg_gpa < 2 || avg_gpa > 6) {
		std::cerr << "Invalud Avg GPA value!" << std::endl;
		return;
	}

	this->average_gpa = avg_gpa;
}

void Student::setBirthDate(Date birthday)
{
	this->birth_date = birthday;
}

// Helpers
// needs reformating to check against month and day and also get the current date
int Student::getAge()
{
	return Date::getCurrentYear() - this->birth_date.getYear();
}

bool Student::isFacultyNumberValid(std::string fac_num)
{
	std::regex regex_expression("[0-9]{9}");

	return regex_match(fac_num, regex_expression);
}

void Student::printStudent()
{
	std::cout << "Student: " << this->name << " " << this->faculty_number << " " << this->average_gpa << " " << this->birth_date.getDay() << "/" << this->birth_date.getMonth() << "/" << this->birth_date.getYear() << "\n" << std::endl;

}

Student::~Student()
{
	//std::cout << "Destructor called for Student: " << std::endl;
	//this->printStudent();
}