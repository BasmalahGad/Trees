// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: BST Tree
// Last Modification Date:
// Author and ID and Group: Youssef Mohamed Salah Eldin Anwar    ID:20210483       Group: S25,26

#ifndef BST_BSTHEADER_H
#define BST_BSTHEADER_H

#include <iostream>
#include <map>
#include <string>
#include "../../Implementations/Application/Student.h"
using namespace std;
class Node
{
public:
    Student stud;
    Node *left;
    Node *right;
    Node()
    {
        stud.setDepartment("N/A");
        stud.setId(0);
        stud.setGPA(0.0);
        stud.setName("None");
        left = NULL;
        right = NULL;
    }
    Node(Student val, Node *l, Node *r)
    {
        stud = val;
        left = l;
        right = r;
    }
};
class BST
{
private:
    Node *root;
    bool Exists(int id);
    map<string,int> department_count;

    //Private Methods
    void DFS(Node *n);

public:
    BST()
    {
        root = NULL;
    }
    void add_student(string Name, int id, double GPA, string Department);
    bool remove_student(int id);
    void search_student(int id);
    void print();
};

#endif // BST_BSTHEADER_H
