#include "StudentOperations.h"
#include <iostream>
using namespace std;

StudentOperations::StudentOperations(vector<Student>& students) : students(students) {}

void StudentOperations::addStudent() {
    Student newStudent;
    cout << "Enter roll number: ";
    cin >> newStudent.roll;
    cout << "Enter name: ";
    cin.ignore(); // Clear newline character from input buffer
    getline(cin, newStudent.name);
    cout << "Enter phone number: ";
    getline(cin, newStudent.phone);
    
    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

void StudentOperations::searchStudentByRoll() {
    int roll;
    cout << "Enter roll to search: ";
    cin >> roll;

    bool found = false;
    for (const auto& student : students) {
        if (student.roll == roll) {
            cout << "Found student: Roll: " << student.roll 
                 << ", Name: " << student.name 
                 << ", Phone: " << student.phone << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found." << endl;
    }
}

void StudentOperations::deleteStudentByRoll() {
    int roll;
    cout << "Enter roll to delete: ";
    cin >> roll;

    for(auto it = students.begin(); it != students.end(); ++it) {
        if (it->roll == roll) {
            students.erase(it);
            cout << "Student with roll " << roll << " deleted successfully!" << endl;
            return;
        }
    }
}


