#ifndef FileOperations_H
#define FileOperations_H

#include"student.h"
#include <vector>
#include <string>
using namespace std;

class FileOperations{
    private:
    vector<Student>&students;
    string filename;
    public:
    FileOperations(vector<Student>&students, const string& filename);

    void loadStudents();
    void saveStudents();
};

#endif