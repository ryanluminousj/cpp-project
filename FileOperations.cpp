#include "FileOperations.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

FileOperations::FileOperations(vector<Student>& students, const string& filename)
    : students(students), filename(filename) { }

void FileOperations::loadStudents(){
    students.clear();

    ifstream file(filename);
    if(!file.is_open()){
        cout<<"Cannot open file:"<<filename<<"\n";
        return;
    }
    string line;
    getline(file, line);

    while(getline(file, line))
    {
        stringstream ss(line);
        string rollStr, name, phone;

        getline(ss, rollStr, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');

        if(rollStr.empty()) continue;

        Student s;
        s.roll = stoi(rollStr);
        s.name = name;
        s.phone = phone;

        students.push_back(s);
    }
    file.close();
}

void FileOperations::saveStudents(){
    ofstream file(filename);
    if(!file.is_open()){
        cout<<"Cannot write to file: "<<filename<<"\n";
        return;
    }
    file << "Roll, Name, Phone\n";
    for(const auto& s:students){
        file<<s.roll<<", "<<s.name<<", "<<s.phone<<"\n";
    }
    file.close();
    cout<<"Data saved successfully.\n";
}