# Course-Management-System
Course  management system written in C++.
## Features

- Print all courses
- Insert a new course
- Delete a course
- Update course information
- Save course list to a text file
- Exit without saving

## Technologies

- C++
- STL Vector
- File Handling (`fstream`)
- String Processing (`strtok`)
- Character Arrays (`char[]`)

## File Format

The program reads course information from **courses.txt**.

Example:

```text
CENG111;Algorithms and Programming I;6.
CENG191;Computer Engineering Orientation;5.
ACS205;Academic Communication Skills III;4.
```

Each record is stored in the following format:

```text
CourseCode;CourseName;ECTS.
```

## Project Structure

```
Course-Management-System/
│── main.cpp
│── courses.txt
│── README.md
```

## How to Run

1. Open the project in your preferred C++ IDE.
2. Make sure `courses.txt` is located in the same directory as the executable.
3. Compile and run the program.

## Menu

1. Print Courses
2. Insert New Course
3. Delete Course
4. Update Course
5. Save and Exit
6. Exit without Saving

## Author

**Buse Ulukaya**
Computer Engineering Student
