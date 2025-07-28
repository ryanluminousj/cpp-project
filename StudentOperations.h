#ifndef STUDENTOPERATIONS_H
#define STUDENTOPERATIONS_H

#include "student.h"
#include <vector>
#include <string>
using namespace std;

class StudentOperations {
private:
    vector<Student>& students;

public:
    StudentOperations(vector<Student>& students);

    void addStudent();
    void searchStudentByRoll();
    void deleteStudentByRoll();
};

#endif