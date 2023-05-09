// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: AVL Tree
// Last Modification Date:
// Author and ID and Group: Abdelrahman Wael Mohammed Hanafy     ID: 20210490      Group: S25,26

#ifndef AVL_AVLHEADER_H
#define AVL_AVLHEADER_H

#include <iostream>
#include "../../Implementations/Application/Student.h"
using namespace std;

class node
{
    public:
    Student student_data;
    node* right;
    node* left;
    int height;

    node()
    {
        student_data.setDepartment("N/A");
        student_data.setId(0);
        student_data.setGPA(0.0);
        student_data.setName("None");
        left = NULL;
        right = NULL;
        height = 0;
    }

};

class AVL
{
    private:
    node* root = nullptr;
    int size = 0;

    void delete_AVL(node* some_node);
    void in_order_traversal(node* some_node);

    public:
    ~AVL()
    {
        delete_AVL(root);
    }
    node* get_root()
    {
        return root;
    }
    int get_size()
    {
        return size;
    }
    int calc_Height(node* some_node); //Done!
    int balance_factor(node* some_node); //Done!
    node* left_left_rotate(node* some_node); //Done!
    node* right_right_rotate(node* some_node); //Done!
    node* left_right_rotate(node* some_node); //Done!
    node* right_left_rotate(node* some_node); //Done!
    node* insert_student(node* some_node, Student some_student); //Done!
    node* delete_student(node* some_node, Student some_student);
    bool search_student(int some_id); //Done!
    void print(); //In Order Traversal   //Done!
};



#endif //AVL_AVLHEADER_H
