#pragma once
#include <string>
#include <vector>

#include "Student.h"

class Classroom
{
private:
	std::string class_name;
	std::vector<Student> students;

public:
	Classroom();
	Classroom(std::string class_name);
	Classroom(std::string class_name, std::vector<Student> students);

	std::string getClassName();
	std::vector<Student> getStudents();

	void setClassName(std::string class_name);
	void addStudent(const Student& student);
	void removeStudent(std::string fac_num);
	int getStudentIndexByFacultyNumber(std::string fac_num);

	void searchByFacultyNumber(std::string fac_num);
	void sortStudents();
	void filterStudentsByGPA();
	void printStudentAgeDistribution();

	static bool isClassNameValid(std::string class_name);

	~Classroom();
};