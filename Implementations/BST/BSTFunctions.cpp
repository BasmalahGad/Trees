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
            cout << "Student with this ID already exists";
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

void BST::search_student(int id)
{
    Node *p = root;
    while (p != NULL)
    {
        if (p->stud.getId() == id)
        {

            cout << "======================";
            cout << endl;
            cout << p->stud.getinfo() << endl;
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
void DFS(Node *n, int &CS, int &IS, int &DS, int &AI, int &IT) // to vISIT all tree elements from leafs
{

    if (n == NULL)
        return;

    // print sub left tree
    DFS(n->left, CS, IS, DS, AI, IT);

    // print root

    if (n->stud.getDepartment() == "CS")
    {
        CS++;
    }
    if (n->stud.getDepartment() == "IS")
    {
        IS++;
    }
    if (n->stud.getDepartment() == "DS")
    {
        DS++;
    }
    if (n->stud.getDepartment() == "AI")
    {
        AI++;
    }
    if (n->stud.getDepartment() == "IT")
    {
        IT++;
    }
    cout << n->stud.getinfo() << endl;

    // print sub right tree
    DFS(n->right, CS, IS, DS, AI, IT);
}

void BST::print()
{
    int CS{}, IS{}, DS{}, AI{}, IT{};
    DFS(root, CS, IS, DS, AI, IT);
    cout << "CS " << CS << " students " << endl;
    cout << "IS " << IS << " students " << endl;
    cout << "DS " << DS << " students " << endl;
    cout << "AI " << AI << " students " << endl;
    cout << "IT " << IT << " students " << endl;
}
void BST::remove_student(int id)
{
    Node *p = root;
    Node *parent = NULL;

    // to get the wanted value
    while (p != NULL)
    {
        if (p->stud.getId() == id)
            break;
        parent = p;
        if (id > p->stud.getId())
            p = p->right;
        else
            p = p->left;
    }
    // case 1 : the node IS not exesting to be deleted
    if (p == NULL)
    {
        cout << "the node is not exesting to be deleted";
        return;
    }
    // case 2 : a node with no children
    if (p->left == NULL && p->right == NULL)
    {
        // to know if it is on the right or left from parent
        if (p->stud.getId() > parent->stud.getId())
        {
            parent->right = NULL;
        }
        else
        {
            parent->left = NULL;
        }
        delete p;
        return;
    }
    // case 3 : a node with no left child
    if (p->left == NULL)
    {
        if (p->stud.getId() > parent->stud.getId())
        {
            parent->right = p->right;
        }
        else
        {
            parent->left = p->right;
        }
        delete p;
        return;
    }

    // case 4 : a node with no right child
    if (p->right == NULL)
    {
        if (p->stud.getId() > parent->stud.getId())
        {
            parent->right = p->left;
        }
        else
        {
            parent->left = p->left;
        }
        delete p;
        return;
    }
    // case 5 : the node is the root it's self or
    // case 6 : a node with two children

    // to get the nearest value of the deleted point
    // we will get the smalest one one it's right
    if (p->right != NULL && p->left != NULL)
    {
        Node *p1 = p->right;

        // getting smallest value on right
        if (p1->left == NULL)
        {
            parent = p1;
            p->stud = p1->stud;
            p->right = parent->right;
            delete p1;
        }
        else
        {
            while (p1->left != NULL)
            {
                parent = p1;
                p1 = p1->left;
            }
            p->stud = p1->stud;
            parent->left = nullptr;
            delete p1;
        }
    }
}
