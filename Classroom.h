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

	const std::string& getClassName() const;
	const std::vector<Student>& getStudents() const;

	void setClassName(const std::string& class_name);
	void addStudent(const Student& student);
	void removeStudent(const std::string& fac_num);

	int searchByFacultyNumber(const std::string& fac_num) const;
	void sortStudents();
	std::vector<Student> filterStudentsByGPA(float gpa_min) const;
	std::vector<Student> filterStudentsByGPA(float gpa_min, float gpa_max) const;
	void printStudentAgeDistribution() const;
	void printStudentAgeDistribution(const Date& date) const;
	float averageClassGPA() const;

	static bool isClassNameValid(const std::string& class_name);
	static void printStudentInfo(const Student& student);

	void printClassStudents() const;

	friend std::ostream& operator<<(std::ostream& out, const Classroom& classroom);

	static bool isFileExtensionValid(const std::string& file_path);
	void saveData(const std::string& file_path) const;
	void loadData(const std::string& file_path);

	~Classroom();
};