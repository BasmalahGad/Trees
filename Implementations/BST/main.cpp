// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: BST Tree
// Last Modification Date:
// Author and ID and Group: Youssef Mohamed Salah Eldin Anwar    ID:20210483       Group: S25,26

#include "BSTFunctions.cpp"

int main()
{
    BST s;
    s.add_student("usf", 2021, 4.0, "is");
    s.add_student("usf", 2020, 4.0, "is");
    s.add_student("usf", 2022, 4.0, "ds");
    s.add_student("usf", 2023, 4.0, "ai");
    s.add_student("usf", 2019, 4.0, "is");
    // s.search_student(2021);
    s.print();

    cout << ":)";
    return 0;
}
