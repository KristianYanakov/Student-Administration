#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "Classroom.h"
#include "Student.h"
#include "Date.h"

Classroom::Classroom()
{
	this->setClassName("Class_B_2019");
}

Classroom::Classroom(std::string class_name)
{
	this->setClassName(class_name);
}

Classroom::Classroom(std::string class_name, std::vector<Student> students)
{
	this->setClassName(class_name);
	this->students = students;
}

// Getters

std::string Classroom::getClassName()
{
	return this->class_name;
}

std::vector<Student> Classroom::getStudents()
{
	return this->students;
}

// Setters & Add & Remove

void Classroom::setClassName(std::string class_name)
{
	if (this->isClassNameValid(class_name)) {
		this->class_name = class_name;
		return;
	}
	std::cerr << "Invalid Class Name: " << class_name << std::endl;
}

void Classroom::addStudent(const Student& student)
{
	this->students.push_back(student);
}

void Classroom::removeStudent(std::string fac_num)
{
	int remove_index = this->getStudentIndexByFacultyNumber(fac_num);
	this->students.erase(this->students.begin() + remove_index);
}

int Classroom::getStudentIndexByFacultyNumber(std::string fac_num)
{
	int index = 0;

	for (Student st : this->students)
	{
		if (st.getFacultyNumber().compare(fac_num))
		{
			return index;
		}
		index++;
	}

	std::cerr << "Classroom has no student with faculty number: " << fac_num << std::endl;
}

// Search & Sort & Filter & Print Age Distribution & Validation

void Classroom::searchByFacultyNumber(std::string fac_num)
{

}

void Classroom::sortStudents()
{

}

void Classroom::filterStudentsByGPA()
{

}

void Classroom::printStudentAgeDistribution()
{

}

bool Classroom::isClassNameValid(std::string class_name)
{

}

Classroom::~Classroom() {
	//std::cout << "Destructor called for Classroom: " << std::endl;
}