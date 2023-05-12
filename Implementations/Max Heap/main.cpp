// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: Max Heap
// Last Modification Date:
// Author3 and ID and Group: Basmala Mohamed Sayed Gad            ID: 20210090      Group: S25,26

#include "MaxHeapHeader.h"

int main() {
    // cout << ":)";
    Student s(20210990,4.11,"bb", "IS");
    Student s1(20213090,2.9,"ali", "IS");
    Student s2(20211090,3.78,"mo", "IS");
    Student s3(20212090,3.2,"ss", "IS");
    Student s4(20212090,7.2,"ss", "IS");
    Student s5(20212090,1.2,"ss", "IS");

    MaxHeap h;
    h.addStudent(s);
    h.addStudent(s1);
    h.addStudent(s2);
    h.addStudent(s3);
    h.addStudent(s4);
    h.addStudent(s5);

    h.sortStudents();
    h.print();
    return 0;
}
