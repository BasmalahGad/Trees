// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: BST Tree
// Last Modification Date:
// Author and ID and Group: Youssef Mohamed Salah Eldin Anwar    ID:20210483       Group: S25,26

#ifndef BST_BSTHEADER_H
#define BST_BSTHEADER_H

#include <iostream>
#include "../../Implementations/Application/Student.h"
using namespace std;
class Node
{
public:
    Student Student;
    Node *left;
    Node *right;
    Node()
    {
        Student.setDepartment("N/A");
        Student.setId(0);
        Student.setGPA(0.0);
        Student.setName("None");
        left = NULL;
        right = NULL;
    }
    Node(int val, Node *l, Node *r)
    {
        value = val;
        left = l;
        right = r;
    }
};
class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = NULL;
    }
    void add_student(string Name, int id, double GPA, string Department);
    void remove_student(int id);
    void search_student(int id);
    bool search(Student s);
    void print();
};

#endif // BST_BSTHEADER_H
