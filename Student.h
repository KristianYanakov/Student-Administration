#pragma once
#include <string>
#include "Date.h"

// Student (Студент): съхранява име (name), факултетен номер (fak_number), среден успех (gpa) и дата на раждане (birth_date – обект от клас Date чрез композиция). 
// Съдържа методи за пресмятане на възраст (getAge), статичен метод за валидация на факултетния номер (isValidFacultyNumber) и предефиниран оператор < за сортиране, 

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
	float getAverageGPA();
	Date getBirthDate();

	void setName(std::string name);
	void setFacultyNumber(std::string fac_num);
	void setAvgGPA(float avg_gpa);
	void setBirthDate(Date birthday);

	int getAge();
	static bool isFacultyNumberValid(std::string fac_num);

	bool operator<(const Student& other_student) const;

	void printStudent();

	~Student();
};