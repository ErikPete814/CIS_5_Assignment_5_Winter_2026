//
//  main.cpp
//  Assignment_5
//
//  Created by Erik Petersen on 7/24/26.
//
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// This is global variable, do not modify
#define MAX_STUDENTS 5

struct Student {
    int studentId;
    string studentName;
    float studentGrades;
};

//have to name functions before main even though they are defined after
void printMenu();
void highestGrade(Student students[], int count);
void lowestGrade(Student students[], int count);
void averageGrade(Student students[], int count);
void printStudentId(Student students[], int count);
void printStudentName(Student students[], int count);

int main() {
    Student students[MAX_STUDENTS];
       int count = 0;
       int choice;

    //students:

       students[0] = {1001, "Alice", 92.5};
       students[1] = {1002, "Bob", 85.0};
       students[2] = {1003, "Charlie", 78.5};
       students[3] = {1004, "Diana", 95.0};
       students[4] = {1005, "Ethan", 88.0};

       count = 5;
    
    //----------------------------------------------------------------------------------------
    //figure out what the user wants and run assosiated function
    do {
        printMenu();
                cout << "Enter your choice: ";
                cin >> choice;
                cin.ignore();
        
        switch (choice) {
        case 1:
            highestGrade(students, count);
            break;
        case 2:
            lowestGrade(students, count);
            break;
        case 3:
            averageGrade(students, count);
            break;
        case 4:
            printStudentId(students, count);
            break;
        case 5:
            printStudentName(students, count);
            break;
        case 6:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void printMenu() {
    cout << "\n=== Student Record System ===\n";
    cout << "1. Find student with the highest grade\n";
    cout << "2. Find the student with the lowest grade\n";
    cout << "3. Find the average grade in the class\n";
    cout << "4. Print all the student's ID\n";
    cout << "5. Print all the student's names\n";
    cout << "6. Exit\n";
}

// function to find the highest grade
void highestGrade(Student students[], int count)
{
    cout << endl;
    if (count == 0) {
        cout << "No students in the record.\n";
        return;
    }
    int highest = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].studentGrades > students[highest].studentGrades) {
            highest = i;
        }
    }
    
    cout << "The student with the highest grade is:" << endl;
    cout << "Name: " << students[highest].studentName << endl;
    cout << "ID: " << students[highest].studentId << endl;
    cout << "Grade: " << students[highest].studentGrades << endl;
    
}
// function to find the lowest grade
void lowestGrade(Student students[], int count)
{
    cout << endl;
    if (count == 0) {
        cout << "No students in the record.\n";
        return;
    }
    
    int lowest = 0;
    for (int i = 1; i < count; i++) {
            if (students[i].studentGrades <students[lowest].studentGrades) {
                lowest = i;
            }
        }

        cout << "The student with the lowest grade is:" << endl;
        cout << "Name: " << students[lowest].studentName << endl;
        cout << "ID: " << students[lowest].studentId << endl;
        cout << "Grade: " << students[lowest].studentGrades << endl;
}
// function to find the average grade
void averageGrade(Student students[], int count)
{
    cout << endl;
    if (count == 0) {
        cout << "No students in the record.\n";
        return;
    }
    double SUM=0;
    for (int i=0; i < count; i++) {
        SUM=students[i].studentGrades + SUM;
    }
    double averageScore=SUM/count;
    cout << fixed << setprecision(1);
    cout << "The average grade in the class is " << averageScore << endl;
}
//function to print student Ids
void printStudentId(Student students[], int count)
{
    cout << endl;
    if (count == 0) {
        cout << "No students in the record.\n";
        return;
    }
    cout << "student Ids:" << endl;
    for (int i=0; i < count; i++) {
        cout << students[i].studentId << endl;
        
    }
}
//function to print student names
void printStudentName(Student students[], int count)
{
    cout << endl;
    if (count == 0) {
        cout << "No students in the record.\n";
        return;
    }
    cout << "student names:" << endl;
    for (int i=0; i < count; i++) {
        cout << students[i].studentName << endl;
        
    }
}
