#pragma once
#include <string>
#include <vector>
#include <ostream>

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

	const std::string getClassName() const;
	const std::vector<Student>& getStudents() const;

	void setClassName(std::string class_name);
	void addStudent(const Student& student);
	void removeStudent(std::string fac_num);

	int searchByFacultyNumber(std::string fac_num);
	void sortStudents();
	void filterStudentsByGPA(float gpa_min);
	void filterStudentsByGPA(float gpa_min, float gpa_max);
	void printStudentAgeDistribution();
	void printStudentAgeDistribution(Date date);
	float averageClassGPA();

	static bool isClassNameValid(std::string class_name);
	static void printStudentInfo(const Student& student);

	void printClassStudents();

	friend std::ostream& operator<<(std::ostream& out, const Classroom& classroom);

	void saveData(const std::string& file_path);
	void loadData(const std::string& file_path);

	~Classroom();
};