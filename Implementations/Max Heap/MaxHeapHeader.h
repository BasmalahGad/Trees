// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: Max Heap
// Last Modification Date:
// Author3 and ID and Group: Basmala Mohamed Sayed Gad            ID: 20210090      Group: S25,26

#ifndef MAX_HEAP_MAXHEAPHEADER_H
#define MAX_HEAP_MAXHEAPHEADER_H

#include <iostream>

using namespace std;

#include "../../Implementations/Application/Student.h"
#include <vector>

class MaxHeap {
private:
    vector<Student> studentsData;

    // to get the indices easily
    int parentOf(int idx);
    int leftChildOf(int idx);
    int rightChildOf(int idx);
    void maxHeapify(int idx, int sz);
    void maxHeapifyUp(int idx);

public:
    // constructor
    MaxHeap() {}

    // methods
    void addStudent(Student &student);
    void sortStudents();
    void print();
    int size();
};

#endif //MAX_HEAP_MAXHEAPHEADER_H
