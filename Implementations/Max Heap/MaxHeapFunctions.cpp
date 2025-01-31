// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: Max Heap
// Last Modification Date:
// Author3 and ID and Group: Basmala Mohamed Sayed Gad            ID: 20210090      Group: S25,26

#include "MaxHeapHeader.h"

int MaxHeap::parentOf(int idx) {
    return (idx - 1) / 2;
}

int MaxHeap::leftChildOf(int idx) {
    return (2 * idx + 1);
}

int MaxHeap::rightChildOf(int idx) {
    return (2 * idx + 2);
}

void MaxHeap::maxHeapify(int idx, int sz) {
    int left = leftChildOf(idx);
    int right = rightChildOf(idx);
    int maxIdx = idx;
    // checks if the left child is larger than its parent and update max element index.
    if (left < sz && studentsData[left].getGPA() > studentsData[maxIdx].getGPA()) {
        maxIdx = left;
    }
    // checks if the right child is larger than its parent and update max element index.
    if (right < sz && studentsData[right].getGPA() > studentsData[maxIdx].getGPA()) {
        maxIdx = right;
    }
    // in case that one child is larger than its parent swap the child with its parent and re-call the function to check the new index.
    if (maxIdx != idx) {
        swap(studentsData[idx], studentsData[maxIdx]);
        maxHeapify(maxIdx, sz);
    }
}

void MaxHeap::addStudent(Student &student) { // add new student and call maxHeapifyUp to save max heap tree properties.
    studentsData.push_back(student);
    maxHeapifyUp(size() - 1);
}

void MaxHeap::maxHeapifyUp(int idx) {
    int parent = parentOf(idx);
    // in case of insertion new element, checks if the parent of this element is smaller than that element and swap them if this is true.
    if (idx > 0 && studentsData[idx].getGPA() > studentsData[parent].getGPA()) {
        swap(studentsData[parent], studentsData[idx]);
        maxHeapifyUp(parent);
        
    }
}

void MaxHeap::sortStudents() {
    for (int i = size() - 1; i > 0; i--) { // using heap sort to sort the students.
        swap(studentsData[0], studentsData[i]);
        maxHeapify(0, i);
    }
}

int MaxHeap::size() {
    return studentsData.size();
}

void MaxHeap::print() { // print the students in reversed order.
    sortStudents();
    int student_counter = 1;
    for (int i = size() - 1; i >= 0; i--) {
        cout << "Student " << student_counter++ << ":\n";
        cout << "ID: " << studentsData[i].getId() << "\n";
        cout << "Name: " << studentsData[i].getName() << "\n";
        cout << "GPA: " << studentsData[i].getGPA() << "\n";
        cout << "Department " << studentsData[i].getDepartment() << "\n";
        cout << "\n";
    }

    //building the manheap again after sorting it
    for(int i = (size()/2)-1; i >= 0;i--)
    {
        maxHeapify(i,size());
    }
}