// FCAI - Data Structures - 2023 - Assignment 1
// Program Name: Trees
// Last Modification Date:
// Author1 and ID and Group: Youssef Mohamed Salah Eldin Anwar    ID:20210483       Group: S25,26
// Author2 and ID and Group: Abdelrahman Wael Mohammed Hanafy     ID: 20210490      Group: S25,26
// Author3 and ID and Group: Basmala Mohamed Sayed Gad            ID: 20210090      Group: S25,26

#ifndef MAIN_CPP_STUDENT_H
#define MAIN_CPP_STUDENT_H

#include <iostream>

using namespace std;

class Student {
private:
    int id;
    double gpa;
    string name;
    string department;

public:
    Student() {}

    Student(int id, double gpa, string name, string depart) {
        this->id = id;
        this->gpa = gpa;
        this->name = name;
        this->department = depart;
    }

    int getId() {
        return this->id;
    }

    void setId(int newId) {
        this->id = newId;
    }

    double getGPA() {
        return this->gpa;
    }

    void setGPA(double newGPA) {
        this->gpa = newGPA;
    }

    string getName() {
        return this->name;
    }

    void setName(string newName) {
        this->name = newName;
    }

    string getDepartment() {
        return this->department;
    }

    void setDepartment(string newDepart) {
        this->department = newDepart;
    }
};

#endif //MAIN_CPP_STUDENT_H
