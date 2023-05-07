// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: BST Tree
// Last Modification Date:
// Author and ID and Group: Youssef Mohamed Salah Eldin Anwar    ID:20210483       Group: S25,26

#include "BSTHeader.h"
void BST::add_student(string Name, int id, double GPA, string Department)
{
    Student s(id, GPA, Name, Department);

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
        if (s.getId() > p->stud.getId())
        {
            if (p->right == NULL)
                break;
            p = p->right;
        }
        else if (s.getId() == p->stud.getId())
        {
            return;
        }
        else
        {
            if (p->left == NULL)
                break;
            p = p->left;
        }
    }
    // p stands at the last node
    if (s.getId() > p->stud.getId())
    {
        p->right = n;
    }
    else
    {
        p->left = n;
    }
}
// bool BST::search(Student S)
// {
//     Node *p = root;
//     while (p != NULL)
//     {
//         if (p->stud.getId() == S.getId())
//             return true;
//         if (S.getId() > p->stud.getId())
//             p = p->right;
//         else
//             p = p->left;
//     }
//     return false;
// }
// void BST::remove_student(int id);
void BST::search_student(int id)
{
    Node *p = root;
    while (p != NULL)
    {
        if (p->stud.getId() == id)
        {
            cout << p->stud.getinfo();
            break;
        }
        else if (p->stud.getId() < id)
            p = p->left;
        else
        {
            p = p->right;
        }
    }
}
void DFS(Node *n, int &cs, int &is, int &ds, int &ai, int &it) // to visit all tree elements from leafs
{

    if (n == NULL)
        return;

    // print sub left tree
    DFS(n->left, cs, is, ds, ai, it);

    // print root

    if (n->stud.getDepartment() == "cs")
    {
        cs++;
    }
    if (n->stud.getDepartment() == "is")
    {
        is++;
    }
    if (n->stud.getDepartment() == "ds")
    {
        ds++;
    }
    if (n->stud.getDepartment() == "ai")
    {
        ai++;
    }
    if (n->stud.getDepartment() == "it")
    {
        it++;
    }
    cout << n->stud.getinfo() << endl;

    // print sub right tree
    DFS(n->right, cs, is, ds, ai, it);
}

void BST::print()
{
    int cs{}, is{}, ds{}, ai{}, it{};
    DFS(root, cs, is, ds, ai, it);
    cout << "CS " << cs << " students " << endl;
    cout << "iS " << is << " students " << endl;
    cout << "dS " << ds << " students " << endl;
    cout << "ai " << ai << " students " << endl;
    cout << "it " << it << " students " << endl;
}