// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: BST Tree
// Last Modification Date:
// Author and ID and Group: Youssef Mohamed Salah Eldin Anwar    ID:20210483       Group: S25,26

#include "BSTFunctions.cpp"

int main()
{
    BST s;
    s.add_student("usf", 2021, 4.0, "IS");
    s.add_student("usf", 2020, 4.0, "IS");
    s.add_student("usf", 2022, 4.0, "DS");
    s.add_student("usf", 2023, 4.0, "AI");
    s.add_student("usf", 2019, 4.0, "IS");
    s.search_student(2021);
    // s.print();

    cout << ":)" << endl;
    s.add_student("usf", 2020, 4.0, "IS");
    cout << endl;
    s.search_student(2025);
    // s.remove_student(2062);
    s.print();
    return 0;
}
