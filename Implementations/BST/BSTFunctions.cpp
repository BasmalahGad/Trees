// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: BST Tree
// Last Modification Date:
// Author and ID and Group: Youssef Mohamed Salah Eldin Anwar    ID:20210483       Group: S25,26

#include "BSTHeader.h"
void BST::add_student(string Name, int id, double GPA, string Department)
{
    Student s(id, GPA, Name, Department);

    if (search(s))
        return;

    Node *n = new Node(s, NULL, NULL);
    if (root == NULL)
    {
        root = n;
        return;
    }
    Node *p = root;

    // getting last node

    while (true)
    {
        // p stands at the root
        if (s.getId() > p->Student.getId())
        {
            if (p->right == NULL)
                break;
            p = p->right;
        }
        else
        {
            if (p->left == NULL)
                break;
            p = p->left;
        }
    }
    // p stands at the last node
    if (s.getId() > p->Student.getId())
    {
        p->right = n;
    }
    else
    {
        p->left = n;
    }
}
bool BST::search(Student S)
{
    Node *p = root;
    while (p != NULL)
    {
        if (p->Student.getId() == S.getId())
            return true;
        if (S.getId() > p->Student.getId())
            p = p->right;
        else
            p = p->left;
    }
    return false;
}
void BST::remove_student(int id);
void BST::search_student(int id)
{
}

void BST::print();