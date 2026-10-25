// StudentAdministration.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Date.h"
#include "Student.h"
#include "Classroom.h"

void testDates()
{
	Date date1(5, 1, 2026);

	//Test Cases For Date
	//date1.setDate(29, 2, 2024); //Valid Leap Year
	//date1.setDate(29, 2, 2026); //Invalid Date
	//date1.setDate(29, 2, 1900); //Invalid
	//date1.setDate(29, 2, 2000); //Valid
	//date1.setDate(31, 4, 2026); //Invalid
	//date1.setDate(31, 4, 2028); //Invalid
	//date1.setDate(31, 4, 1800); //Invalid

	std::cout << date1 << std::endl;
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

void testClassroomOperations()
{
	// Initialize valid classroom (Matches "^Class_[A-Z]_20[0-9]{2}$")
	Classroom myClass("Class_A_2024");

	// Mock Data: 5 Students with spread GPAs and birth dates
	Student s1("Alice Johnson", "111111111", 5.80, Date(15, 5, 2005)); // ~Age 21
	Student s2("Bob Smith", "222222222", 4.50, Date(20, 8, 2004)); // ~Age 22
	Student s3("Charlie Brown", "333333333", 3.20, Date(10, 1, 2005)); // ~Age 21
	Student s4("Diana Prince", "444444444", 6.00, Date(30, 12, 2006)); // ~Age 19
	Student s5("Evan Wright", "555555555", 4.50, Date(5, 5, 2005)); // ~Age 21

	//Student s6("Test", "000000000", 4.50, Date(5, 5, 2002)); // ~Age 24

	myClass.addStudent(s1);
	myClass.addStudent(s2);
	myClass.addStudent(s3);
	myClass.addStudent(s4);
	myClass.addStudent(s5);

	//myClass.printClassStudents();

	//myClass.addStudent(s6);

	// --- TEST 1: Search ---
	 //std::cout << "--- Testing Search ---\n";
	 //myClass.searchByFacultyNumber("333333333"); // Should print Charlie Brown 

	// --- TEST 2: Sort ---
	 //std::cout << "\n--- Testing Sort ---\n";
	 //myClass.sortStudents(); // Should print Charlie(3.20) -> Bob(4.50) -> Evan(4.50) -> Alice(5.80) -> Diana(6.00)

	// --- TEST 3: Filter ---
	 //std::cout << "\n--- Testing Filter (> 5.0) ---\n";
	 //myClass.filterStudentsByGPA(5.0); // Should print Alice and Diana

	// std::cout << "\n--- Testing Filter Range (4.0 - 5.0) ---\n";
	 //myClass.filterStudentsByGPA(4.0, 5.0); // Should print Bob and Evan

	// --- TEST 4: Age Distribution ---
	// std::cout << "\n--- Testing Age Distribution ---\n";
	 //myClass.printStudentAgeDistribution(); 
	 //myClass.printStudentAgeDistribution(Date(5, 9, 2020)); 

	// Expected output depending on current date: Three 21-year-olds, one 22-year-old, one 19/20-year-old.

	// --- TEST 5: Remove ---
	 //std::cout << "\n--- Testing Remove ---\n";
	 //myClass.removeStudent("22222222"); // Should remove Bob
	 //myClass.searchByFacultyNumber("222222222");
	 //myClass.printClassStudents();

	 //myClass.removeStudent("123456789"); // No such fac num
	 //myClass.searchByFacultyNumber("123456789");
	 //myClass.printClassStudents();

	// --- TEST 6: AVG GPA ---
	//std::cout << "\n--- Testing AVG GPA ---\n";
	//myClass.averageClassGPA();

	// --- TEST 7: Predefined << operator
	//std::cout << s1 << std::endl;
	//std::cout << s2 << std::endl;
	//std::cout << s3 << std::endl;
	//std::cout << s4 << std::endl;
	//std::cout << s5 << std::endl;

	// --- TEST 8: Predefine << for classroom
	std::cout << myClass;
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

	testClassroomOperations();

}
