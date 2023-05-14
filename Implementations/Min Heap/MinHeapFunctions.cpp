// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: Min Heap
// Last Modification Date:
// Author3 and ID and Group: Basmala Mohamed Sayed Gad            ID: 20210090      Group: S25,26

#include "MinHeapHeader.h"

int MinHeap::parentOf(int idx) {
    return (idx - 1) / 2;
}

int MinHeap::leftChildOf(int idx) {
    return (2 * idx + 1);
}

int MinHeap::rightChildOf(int idx) {
    return (2 * idx + 2);
}

void MinHeap::minHeapify(int idx, int sz) {
    int left = leftChildOf(idx);
    int right = rightChildOf(idx);
    int minIdx = idx;
    // checks if the left child is smaller than its parent and update max element index.
    if (left < sz && studentsData[left].getGPA() < studentsData[minIdx].getGPA()) {
        minIdx = left;
    }
    // checks if the right child is smaller than its parent and update max element index.
    if (right < sz && studentsData[right].getGPA() < studentsData[minIdx].getGPA()) {
        minIdx = right;
    }
    // in case that one child is smaller than its parent swap the child with its parent and re-call the function to check the new index.
    if (minIdx != idx) {
        swap(studentsData[idx], studentsData[minIdx]);
        minHeapify(minIdx, sz);
    }
}

void MinHeap::addStudent(Student &student) { // add new student and call mixHeapifyUp to save max heap tree properties.
    studentsData.push_back(student);
    minHeapifyUp(size() - 1);
}

void MinHeap::minHeapifyUp(int idx) {
    int parent = parentOf(idx);
    // in case of insertion new element, checks if the parent of this element is larger than that element and swap them if this is true.
    if (idx > 0 && studentsData[idx].getGPA() < studentsData[parent].getGPA()) {
        swap(studentsData[parent], studentsData[idx]);
        minHeapifyUp(parent);
    }
}

void MinHeap::sortStudents(){
    for (int i = size() - 1; i > 0; i--) { // using heap sort to sort the students.
        swap(studentsData[0], studentsData[i]);
        minHeapify(0, i);
    }
}

int MinHeap::size() {
    return studentsData.size();
}

void MinHeap::print() { // print the students in reversed order.
    int student_counter = 1;

    sortStudents();
    for (int i = size() - 1; i >= 0; i--) {
        cout << "Student " << student_counter++ << ":\n";
        cout << "ID: " << studentsData[i].getId() << "\n";
        cout << "Name: " << studentsData[i].getName() << "\n";
        cout << "GPA: " << studentsData[i].getGPA() << "\n";
        cout << "Department " << studentsData[i].getDepartment() << "\n";
        cout << "\n";
    }

    //building the minheap again after sorting it
    for(int i = (size()/2)-1; i >= 0;i--)
    {
        minHeapify(i,size());
    }

}