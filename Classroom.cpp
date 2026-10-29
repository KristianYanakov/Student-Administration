#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <optional>
#include <ranges>
#include <map>
#include <fstream>
#include <sstream>
#include "Classroom.h"

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

const std::string Classroom::getClassName() const
{
	return this->class_name;
}

const std::vector<Student>& Classroom::getStudents() const
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
	int remove_index = this->searchByFacultyNumber(fac_num);
	
	if (remove_index == -1)
	{
		std::cerr << "No student with such faculty number was found and consequently not deleted: " << fac_num << std::endl;
		return;
	}

	this->students.erase(this->students.begin() + remove_index);
}

// Search & Sort & Filter & Print Age Distribution & Validation

int Classroom::searchByFacultyNumber(std::string fac_num)
{
	int index = 0;

	for (const Student& st : this->students)
	{
		if (!st.getFacultyNumber().compare(fac_num))
		{
			Student stud = this->students[index];
			stud.printStudent();
			return index;
		}
		index++;
	}
	
	std::cerr << "Classroom has no student with faculty number: " << fac_num << std::endl;
	return -1;
}

void Classroom::sortStudents()
{
	sort(this->students.begin(), this->students.end());

	std::cout << "Sorted Classroom: " << this->class_name << std::endl;

	for (const Student& s : this->students)
	{
		s.printStudent();
	}
}

void Classroom::filterStudentsByGPA(float gpa_min)
{
	std::vector<Student> filtered;

	for (const Student& s : this->students)
	{
		if (s.getAverageGPA() > gpa_min)
		{
			filtered.push_back(s);
			s.printStudent();
		}
	}

	if (filtered.size() == 0)
	{
		std::cerr << "No students match the filter!" << std::endl;
	}
}

void Classroom::filterStudentsByGPA(float gpa_min, float gpa_max)
{
	std::vector<Student> filtered;

	for (const Student& s : this->students)
	{
		if (s.getAverageGPA() > gpa_min && s.getAverageGPA() < gpa_max)
		{
			filtered.push_back(s);
			s.printStudent();
		}
	}

	if (filtered.size() == 0)
	{
		std::cerr << "No students match the filter!" << std::endl;
	}
}

//Default with the current date
void Classroom::printStudentAgeDistribution()
{
	std::map<int, int> age_distribution;
	int curr_student_age = 0;

	for (const Student& s : this->students)
	{
		curr_student_age = s.getAge();
		age_distribution[curr_student_age] += 1;
			
	}

	for (auto item : age_distribution) {
		std::cout << "Age: " << item.first << " Number of Students that age: " << item.second << "\n";
	}
}

//With custom date
void Classroom::printStudentAgeDistribution(Date date)
{
	std::map<int, int> age_distribution;
	int curr_student_age = 0;

	for (const Student& s : this->students)
	{
		curr_student_age = s.getAge(date);
		age_distribution[curr_student_age] += 1;

	}

	for (auto item : age_distribution) {
		std::cout << "Age: " << item.first << " Number of Students that age: " << item.second << "\n";
	}
}

float Classroom::averageClassGPA()
{
	float avg_grade = 0;

	if (this->students.size() == 0) {
		std::cerr << "No members in this class!" << std::endl;
		return -1;
	}

	for (const Student& s : this->students) 
	{
		avg_grade += s.getAverageGPA();
	}

	avg_grade /= this->students.size();

	std::cout << "Class: " << this->class_name << "Average GPA is : " << avg_grade << std::endl;
	return avg_grade;
}

bool Classroom::isClassNameValid(std::string class_name)
{
	std::regex regex_expression("^Class_[A-Z]_20[0-9]{2}$"); // Class_B_2019

	return regex_match(class_name, regex_expression);
}

void Classroom::printClassStudents()
{
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Students of Class - " << this->class_name << "\n"  << std::endl;
	for (const Student& s : this->students)
	{
		s.printStudent();
	}
	std::cout << "------------------------------------------" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Classroom& classroom)
{
	out << classroom.getClassName() << "\n";

	for (const auto& s : classroom.getStudents())
	{
		out << s << "\n";
	}

	return out;
}

bool Classroom::isFileExtensionValid(const std::string& file_path)
{
	std::string suffix = "";
	for (int i = file_path.size() - 4; i < file_path.size(); i++) {
		suffix += file_path[i];
		//std::cout << suffix << std::endl;
	}

	return !suffix.compare(".csv");
}

void Classroom::saveData(const std::string& file_path)
{
	if (!isFileExtensionValid(file_path))
	{
		std::cerr << "File path is pointing to a non .csv file! Type not supported!";
		return;
	}

	const std::vector<Student>& students_in_class = this->getStudents();

	std::fstream data_file;
	data_file.open(file_path, std::ios::out);

	if (data_file.is_open())
	{
		data_file << this->getClassName() << std::endl;

		for (const Student& s : students_in_class) {
			data_file
				<< s.getName() << ","
				<< s.getFacultyNumber() << ","
				<< s.getAverageGPA() << ","
				<< s.getBirthDate().getDay() << ","
				<< s.getBirthDate().getMonth() << ","
				<< s.getBirthDate().getYear()
				<< std::endl;
		}
	}

	data_file.close();
}

void Classroom::loadData(const std::string& file_path)
{
	if (!isFileExtensionValid(file_path))
	{
		std::cerr << "File path is pointing to a non .csv file! Type not supported!";
		return;
	}

	int counter = 0;

	std::fstream data_file;
	data_file.open(file_path, std::ios::in);

	if (data_file.is_open())
	{
		std::string current_line;

		this->students.clear();

		while (std::getline(data_file, current_line))
		{	
			if (current_line.empty()) continue;

			if (counter == 0)
			{
				this->setClassName(current_line);
				counter++;

				continue;
			}
			
			std::stringstream ss(current_line);
			
			std::string curr_student_name;
			std::string curr_faculty_number;
			std::string curr_gpa;
			std::string curr_birthday_day;
			std::string curr_birthday_month;
			std::string curr_birthday_year;

			std::getline(ss, curr_student_name, ',');
			std::getline(ss, curr_faculty_number, ',');
			std::getline(ss, curr_gpa, ',');
			std::getline(ss, curr_birthday_day, ',');
			std::getline(ss, curr_birthday_month, ',');
			std::getline(ss, curr_birthday_year, ',');			

			this->addStudent(Student(curr_student_name, curr_faculty_number, std::stof(curr_gpa), Date(std::stoi(curr_birthday_day), std::stoi(curr_birthday_month), std::stoi(curr_birthday_year))));
		}
	}

	data_file.close();
}

Classroom::~Classroom() {
	//std::cout << "Destructor called for Classroom: " << std::endl;
}