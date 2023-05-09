// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: AVL Tree
// Last Modification Date:
// Author and ID and Group: Abdelrahman Wael Mohammed Hanafy     ID: 20210490      Group: S25,26

#include "AVLFunctions.cpp"

int main() {

    AVL a1;
    Student s1(1,4,"Ahmed","CS");
    Student s2(2,4,"mo","IS");
    // Student s4(7,4,"kk","DS");
    Student s3(3,4,"omer","AI");

    a1.insert_student(a1.get_root(),s1);
    a1.insert_student(a1.get_root(),s3);
    a1.insert_student(a1.get_root(),s2);
    // a1.insert_student(a1.get_root(),s4);

    a1.print();

    // cout << a1.get_root()->right->right->student_data.getinfo();

    // cout << ":)";
    return 0;
}
