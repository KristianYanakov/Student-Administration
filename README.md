# Student Administration System

## 📌 Project Overview
This project is an Object-Oriented C++ application designed for the administration, validation, and processing of student data. Developed as a university course project, it strongly emphasizes core OOP principles such as **Encapsulation**, **Composition**, and **Aggregation**. 

The system allows users to manage a classroom of students, validate personal and academic information, perform statistical calculations, and persist data using `.csv` files.

## ✨ Key Features
- **Data Validation & Robustness:** 
  - Strict calendar date validation (including leap year calculations).
  - Regular Expression (Regex) validation for Faculty Numbers (exactly 9 digits).
  - Regex validation for Classroom names (e.g., `Class_B_2019`).
- **Advanced Filtering & Sorting:**
  - Sort students by GPA using an overloaded `<` operator.
  - Filter students by minimum GPA or a specific GPA range.
- **Statistical Analytics:**
  - Calculate the classroom's average GPA.
  - Generate an age distribution report (how many students are a certain age) based on the current date or a custom specified date.
- **File I/O Operations:**
  - Save and load classroom data to and from `.csv` files, ensuring data persistence between sessions.
- **Operator Overloading:** Custom stream insertion operators (`<<`) for neatly formatted console output of Dates, Students, and entire Classrooms.

## 🏗️ Architecture & OOP Design
The system architecture revolves around three main classes:

### 1. `Date` Class
*   **Role:** Handles calendar dates.
*   **Features:** Validates day, month, and year combinations. Accounts for leap years mathematically. Retrieves the current system date using the `<chrono>` library.

### 2. `Student` Class
*   **Role:** Represents an individual student.
*   **Design:** Utilizes **Composition** by embedding a `Date` object (`birth_date`) as a private member.
*   **Features:** Stores name, faculty number, and GPA. Contains methods to calculate the student's exact age based on their birth date and a target date.

### 3. `Classroom` Class
*   **Role:** Acts as a container/manager for the students.
*   **Design:** Utilizes **Aggregation** by maintaining a `std::vector<Student>`.
*   **Features:** Handles group operations such as adding/removing students, searching by faculty number, filtering, sorting, calculating statistics, and handling file persistence.

## 🛠️ Technologies & Libraries Used
- **Language:** C++ (Requires C++20 support for `<chrono>` calendar features)
- **Standard Libraries:** `<iostream>`, `<string>`, `<vector>`, `<regex>`, `<algorithm>`, `<map>`, `<fstream>`, `<sstream>`, `<chrono>`

## 🚀 How to Build and Run

### Prerequisites
You need a C++ compiler that supports the C++20 standard (e.g., GCC 10+, Clang 10+, or MSVC 19.28+).

### Compilation
If you are using `g++` via the command line, navigate to the project directory and compile the `.cpp` files together:

```bash
g++ -std=c++20 Date.cpp Student.cpp Classroom.cpp StudentAdministration.cpp -o StudentAdmin
```

### Execution
Run the compiled executable:
```bash
# On Linux/macOS
./StudentAdmin

# On Windows
StudentAdmin.exe
```
*(Note: The main file `StudentAdministration.cpp` currently contains various commented-out test functions. You can uncomment specific tests in `main()` to see the functionalities in action).*

## 📁 File Structure & Data Persistence
The `Classroom` class can serialize its state to a `.csv` file. The format used is as follows:

```csv
Class_A_2024
Alice Johnson,111111111,5.8,15,5,2005
Bob Smith,222222222,4.5,20,8,2004
```
- **Line 1:** Classroom Name
- **Subsequent Lines:** `Name, FacultyNumber, GPA, BirthDay, BirthMonth, BirthYear`

*Make sure the target directory (e.g., `saved_data/`) exists before running the save operations, or update the path in the driver code.*