// FCAI - Data Structures - 2023 - Assignment 1
// Program Name: Trees
// Last Modification Date:
// Author1 and ID and Group: Youssef Mohamed Salah Eldin Anwar    ID:20210483       Group: S25,26
// Author2 and ID and Group: Abdelrahman Wael Mohammed Hanafy     ID: 20210490      Group: S25,26
// Author3 and ID and Group: Basmala Mohamed Sayed Gad            ID: 20210090      Group: S25,26

#ifndef MAIN_CPP_APPLICATIONHEADER_H
#define MAIN_CPP_APPLICATIONHEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "../../Implementations/AVL/AVLHeader.h"
#include "../../Implementations/BST/BSTHeader.h"
#include "../../Implementations/Max Heap/MaxHeapHeader.h"
#include "../../Implementations/Min Heap/MinHeapHeader.h"
using namespace std;

class Application{
private:
    vector<Student> studentsDate;
    void readFile(vector<Student>& students);
    void BST_menu(BST& bst);
    void AVL_menu(AVL& avl);
    void MaxHeap_menu(MaxHeap& mxHeap);
    void MinHeap_menu(MinHeap& miHeap);

public:
    void Application_menu();
};
#endif
