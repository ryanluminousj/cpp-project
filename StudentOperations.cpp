#include "StudentOperations.h"
#include<algorithm>
#include <iostream>
using namespace std;

StudentOperations::StudentOperations(vector<Student>& students) : students(students) {}

void StudentOperations::addStudent() {
    Student newStudent;
    cout << "Enter roll number: ";
    cin >> newStudent.roll;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, newStudent.name);
    cout << "Enter phone number: ";
    getline(cin, newStudent.phone);
    
    students.push_back(newStudent);
    cout << "Student added successfully!" << endl;
}

void StudentOperations::searchStudentByName() {
    string name;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, name);

    //convert input to lowercase
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    bool found = false;
    for (const auto& student : students) {
        string studentNameLower = student.name;
        transform(studentNameLower.begin(), studentNameLower.end(), studentNameLower.begin(), ::tolower);
        if (studentNameLower == name) {
            cout << "Found student: Name: " << student.name 
                 << ", Roll: " << student.roll 
                 << ", Phone: " << student.phone << endl;
            found = true;
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

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->roll == roll) {
            students.erase(it);
            cout << "Student with roll " << roll << " deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student with roll " << roll << " not found." << endl;
}