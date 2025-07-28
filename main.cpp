#include <iostream>
#include <vector>
#include "FileOperations.h"
#include "StudentOperations.h"

using namespace std;

int main() {
    vector<Student> students;

    // Load from CSV file using Samip's class
    FileOperations fileOps(students, "student-details.csv");
    fileOps.loadStudents();

    // Handle user actions using Johnson's class
    StudentOperations studentOps(students);

    int choice;
    do {
        cout << "\n===== Student Management Menu =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student by Roll\n";
        cout << "3. Delete Student by Roll\n";
        cout << "4. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                studentOps.addStudent();
                break;
            case 2:
                studentOps.searchStudentByRoll();
                break;
            case 3:
                studentOps.deleteStudentByRoll();
                break;
            case 4:
                fileOps.saveStudents();
                cout << "Exiting... Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}

