// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: Min Heap
// Last Modification Date:
// Author3 and ID and Group: Basmala Mohamed Sayed Gad            ID: 20210090      Group: S25,26

#ifndef MIN_HEAP_MINHEAPHEADER_H
#define MIN_HEAP_MINHEAPHEADER_H

#include <iostream>
using namespace std;

#include "../../Implementations/Application/Student.h"
#include <vector>

class MinHeap{
private:
    vector<Student> studentsData;

    // to get the indices easily
    int parentOf(int idx);
    int leftChildOf(int idx);
    int rightChildOf(int idx);
    void minHeapify(int idx, int sz);
    void minHeapifyUp(int idx);

public:
    // constructor
    MinHeap(){}

    // methods
    void addStudent(Student& student);
    void sortStudents();
    void print();
    int size();
};
#endif //MIN_HEAP_MINHEAPHEADER_H
