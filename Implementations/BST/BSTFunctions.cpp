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
            cout << "Student with this ID already exists" << endl;
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
bool BST::Exists(int id)
{
    Node *p = root;
    while (p != NULL)
    {
        if (p->stud.getId() == id)
            return true;
        if (id > p->stud.getId())
            p = p->right;
        else
            p = p->left;
    }
    return false;
}

void BST::search_student(int id)
{
    Node *p = root;
    if (!Exists(id))
    {
        cout << "Student Not Found!" << endl;
        return;
    }
    while (p != NULL)
    {
        if (p->stud.getId() == id)
        {

            cout << "======================";
            cout << endl;
            cout << p->stud.getinfo() << endl;
            break;
        }
        else if (p->stud.getId() > id)
            p = p->left;
        else
        {
            p = p->right;
        }
    }
}
void BST::DFS(Node *n) // to vISIT all tree elements from leafs
{

    if (n == NULL)
        return;

    // print sub left tree
    DFS(n->left);

    // print root
    cout << "\n";
    cout << "ID: " << n->stud.getId()<< "\n";
    cout << "Name: " << n->stud.getName() << "\n";
    cout << "GPA: " << n->stud.getGPA() << "\n";
    cout << "Department " << n->stud.getDepartment() << "\n";
    department_count[n->stud.getDepartment()]++; //to count the departments

    // print sub right tree
    DFS(n->right);
}

void BST::print()
{
    //clearing the map before counting
    department_count.clear();
    DFS(root);

    cout << "\n";
    cout << "Students per Departments:" << endl;

    auto it = department_count.begin();
    while(it != department_count.end())
    {
        cout << it->first << ": " << it->second << " Students" << endl;
        it++;
    }

}



bool BST::remove_student(int id)
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
        cout << "the node is not exesting to be deleted\n";
        return false;
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
        return true;
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
        return true;
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
        return true;
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
            return true;
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
            return true;
        }
    }

    return false;
}
