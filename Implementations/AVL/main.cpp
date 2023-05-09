// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: AVL Tree
// Last Modification Date:
// Author and ID and Group: Abdelrahman Wael Mohammed Hanafy     ID: 20210490      Group: S25,26

#include "AVLFunctions.cpp"

int main() {

    AVL a1;
    Student s1(1,4,"Ahmed","CS");
    Student s2(2,4,"mo","IS");
    Student s4(4,4,"kk","DS");
    Student s3(3,4,"omer","AI");
    Student s5(5,4,"omer","AI");

    a1.insert_student(a1.get_root(),s1);
    a1.insert_student(a1.get_root(),s2);
    a1.insert_student(a1.get_root(),s3);
    // a1.insert_student(a1.get_root(),s4);
    // a1.insert_student(a1.get_root(),s5);

    a1.print();
    // a1.search_student(2);
    cout << a1.get_size() << endl;

    // cout << "delete" << endl;
    a1.delete_student(a1.get_root(),2);
    a1.delete_student(a1.get_root(),1);
    a1.delete_student(a1.get_root(),3);

    cout << a1.get_size() << endl;

    
    // a1.delete_student(a1.get_root(),3);
    // a1.search_student(2);
    // a1.search_student(3);

    cout << endl;
    a1.print();
    cout << endl;
    // cout << a1.get_root()->student_data.getinfo() << endl;
    cout << endl;
    a1.search_student(2);

    // cout << a1.get_root()->right->right->student_data.getinfo();

    // cout << ":)";
    return 0;
}
