#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

class Course {
public:
    char courseCode[8];
    char courseName[80];
    int ECTS;
};

vector<Course> allCourses;

void insertNewCourse();
void deleteCourse();
void updateCourse();
void saveAndEXit();
void exitWithoutSaving();
void printCourses();

int courseNumber = 0;

int main() {
    int choice;
    string course;
    char array[200];

    ifstream CourseFile("courses.txt");

    if (CourseFile.is_open()) {
        while (getline(CourseFile, course)) {
            Course newCourse;

            strcpy(array, course.c_str());

            char* token;

            token = strtok(array, ";");
            strcpy(newCourse.courseCode, token);

            token = strtok(nullptr, ";");
            strcpy(newCourse.courseName, token);

            token = strtok(nullptr, ".");
            newCourse.ECTS = atoi(token);

            allCourses.push_back(newCourse);
            courseNumber++;
        }

        CourseFile.close();
    }
    else {
        cerr << "There is no such file." << endl;
    }

    cout << "COURSE MANAGEMENT" << endl;

    while (1) {
        cout << "1. Print Courses" << endl;
        cout << "2. Insert New Courses" << endl;
        cout << "3. Delete Course" << endl;
        cout << "4. Update Course" << endl;
        cout << "5. Save and Exit" << endl;
        cout << "6. Exit without Saving" << endl;
        cout << "Please do choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printCourses();
            break;
        case 2:
            insertNewCourse();
            break;
        case 3:
            deleteCourse();
            break;
        case 4:
            updateCourse();
            break;
        case 5:
            saveAndEXit();
            break;
        case 6:
            exitWithoutSaving();
            break;
        default:
            cout << "Invalid choice." << endl;
        }

        putchar('\n');
    }

    return 0;
}

void insertNewCourse() {
    Course newCourse;
    char courseCodeToInserted[8];
    char courseNameToInserted[80];
    int ectsCreditToInserted;
    bool found = false;

    cin.ignore();

    cout << "Please enter the code for the course you want to enroll in: ";
    cin.getline(courseCodeToInserted, 8);

    for (int i = 0; i < courseNumber; i++) {
        if (strcmp(courseCodeToInserted, allCourses.at(i).courseCode) == 0) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "The course is already registered." << endl;
        return;
    }

    cout << "Please enter the name for the course you want to enroll in: ";
    cin.getline(courseNameToInserted, 80);

    cout << "Please enter the ECTS credit for the course you want to enroll in: ";
    cin >> ectsCreditToInserted;

    strcpy(newCourse.courseCode, courseCodeToInserted);
    strcpy(newCourse.courseName, courseNameToInserted);
    newCourse.ECTS = ectsCreditToInserted;

    allCourses.push_back(newCourse);
    courseNumber++;
}

void deleteCourse() {
    bool found = false;
    char courseCodeToDeleted[8];

    cin.ignore();

    cout << "Please enter the code for the course you want to delete in: ";
    cin.getline(courseCodeToDeleted, 8);

    for (int i = 0; i < courseNumber; i++) {
        if (strcmp(courseCodeToDeleted, allCourses.at(i).courseCode) == 0) {
            found = true;
            allCourses.erase(allCourses.begin() + i);
            courseNumber--;
            break;
        }
    }

    if (!found) {
        cout << "There is not this course." << endl;
    }
}

void updateCourse() {
    char courseCodeToUpdated[8];
    char courseNameToUpdated[80];
    int ectsCreditToUpdated;
    bool found = false;

    cin.ignore();

    cout << "Please enter the code for the course you want to update in: ";
    cin.getline(courseCodeToUpdated, 8);

    for (int i = 0; i < courseNumber; i++) {
        if (strcmp(courseCodeToUpdated, allCourses.at(i).courseCode) == 0) {
            found = true;

            cout << "Please enter the name for the course you want to update in: ";
            cin.getline(courseNameToUpdated, 80);

            cout << "Please enter the ECTS credit for the course you want to update in: ";
            cin >> ectsCreditToUpdated;

            strcpy(allCourses.at(i).courseName, courseNameToUpdated);
            allCourses.at(i).ECTS = ectsCreditToUpdated;

            break;
        }
    }

    if (!found) {
        cout << "There is not this course." << endl;
    }
}

void saveAndEXit() {
    ofstream CourseFile("courses.txt");

    for (int i = 0; i < courseNumber; i++) {
        CourseFile << allCourses.at(i).courseCode;
        CourseFile << ";";
        CourseFile << allCourses.at(i).courseName;
        CourseFile << ";";
        CourseFile << allCourses.at(i).ECTS;
        CourseFile << "." << endl;
    }

    CourseFile.close();
    exit(0);
}

void exitWithoutSaving() {
    exit(0);
}

void printCourses() {
    if (allCourses.size() == 0) {
        cout << "There are no courses." << endl;
    }
    cout << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < courseNumber; i++) {
        cout << "Course Code : " << allCourses.at(i).courseCode << endl;
        cout << "Course Name : " << allCourses.at(i).courseName << endl;
        cout << "ECTS        : " << allCourses.at(i).ECTS << endl;
        cout << "----------------------------------------" << endl;
    }
}
