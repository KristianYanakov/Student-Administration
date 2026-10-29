#pragma once
#include <string>
#include <ostream>
#include <vector>

#include "Date.h"

class Student {
private:
	std::string name;
	std::string faculty_number;
	float average_gpa;
	Date birth_date;  

public:
	Student();
	Student(std::string name, std::string fac_num, float avg_gpa, Date birthday);
	
	const std::string& getName() const;
	const std::string& getFacultyNumber() const;
	float getAverageGPA() const;
	Date getBirthDate() const;

	void setName(const std::string& name);
	void setFacultyNumber(const std::string& fac_num);
	void setAvgGPA(float avg_gpa);
	void setBirthDate(const Date& birthday);
	
	int getAge() const;
	int getAge(const Date& date) const;
	static bool isFacultyNumberValid(const std::string& fac_num);

	bool operator<(const Student& other_student) const;

	void printStudent() const;

	friend std::ostream& operator<<(std::ostream& out, const Student& student);
	//friend std::ostream& operator<<(std::ostream& out, const std::vector<Student>& students);

	~Student();
};
