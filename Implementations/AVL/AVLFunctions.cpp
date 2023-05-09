// FCAI - Data Structures - 2023 - Assignment 2
// Program Name: AVL Tree
// Last Modification Date:
// Author and ID and Group: Abdelrahman Wael Mohammed Hanafy     ID: 20210490      Group: S25,26

#include "AVLHeader.h"

int AVL::calc_Height(node* some_node)
{
    if(some_node->left != nullptr && some_node->right != nullptr) //if its not a leaf and has a right and left node
    {
        if(some_node->left->height > some_node->right->height)
        {
            return some_node->left->height + 1;
        }
        else
        {
            return some_node->right->height + 1;
        }
    }
    else if(some_node->left == nullptr && some_node->right != nullptr) //if it has a right only 
    {
        return some_node->right->height + 1;
    }
    else if(some_node->left != nullptr && some_node->right == nullptr) // if it has a left only
    {
        return some_node->left->height + 1;
    }

    return 0; //if its a leaf (some_node->left == nullptr && some_node->right == nullptr)
}

int AVL::balance_factor(node* some_node)
{
    if(some_node == nullptr)
    {
        return 0;
    }
    if(some_node->left != nullptr && some_node->right != nullptr) //if its not a leaf and has a right and left node
    {
        return some_node->left->height - some_node->right->height;
    }
    else if(some_node->left == nullptr && some_node->right != nullptr) //if it has a right only 
    {
        return (-1*(some_node->right->height));
    }
    else if(some_node->left != nullptr && some_node->right == nullptr) // if it has a left only
    {
        return some_node->left->height;
    }

    return 0;
}

node* AVL::left_left_rotate(node* some_node)
{
    node* temp = some_node->left;
    some_node->left = temp->right;
    temp->right = some_node;

    if(some_node == root)
    {
        root = temp;
    }

    // cout << "ll" << endl;

    return temp;
}

node* AVL::right_right_rotate(node* some_node)
{
    node* temp = some_node->right;
    some_node->right = temp->left;
    temp->left = some_node;

    if(some_node == root)
    {
        root = temp;
    }

    // cout << "rr" << endl;

    return temp;
}

node* AVL::left_right_rotate(node* some_node)
{
    node* temp = some_node->left;
    some_node->left = right_right_rotate(temp); //doing the right rotate first
    return left_left_rotate(some_node); //then we do the left rotate
}

node* AVL::right_left_rotate(node* some_node)
{
    node* temp = some_node->right;
    some_node->right = left_left_rotate(temp); //doing the left rotate first
    return right_right_rotate(some_node); //then we do the right rotate
}

node* AVL::insert_student(node* some_node, Student some_student)
{
    if(some_node == nullptr) //base case
    {
        node* new_node = new node;

        new_node->student_data = some_student;
        new_node->left = nullptr;
        new_node->right = nullptr;
        new_node->height = 1;

        if(size == 0)
        {
            root = new_node;
        }
            
        size++;
        return new_node;
    }
    else //recuresive case
    {
        if(some_student.getId() < some_node->student_data.getId())
        {
            some_node->left = insert_student(some_node->left,some_student);
        }
        else
        {
            some_node->right = insert_student(some_node->right,some_student);
        }
    }

    some_node->height = calc_Height(some_node); //calculating the new height of the root after inserting the node

    //calculationg the balance factor
    //some important rules:
    //balance factor = left->height - right->height
    //if the balance factor == 1 or -1 or 0 then the tree is balanced
    //if the balance factor > 1 (more positive) then the tree is skewed to the left 
    //if the balance factor < -1 (more negative) then the tree is skewed to the right

    if(balance_factor(some_node) > 1 && balance_factor(some_node->left) == 1) //two positive numbers so we go with left left rotation
    {
        some_node = left_left_rotate(some_node);
    }
    else if(balance_factor(some_node) > 1 && balance_factor(some_node->left) == -1) //one positive number -> left, one negative number -> right
    {
        some_node = left_right_rotate(some_node);
    }
    else if(balance_factor(some_node) < -1 && balance_factor(some_node->right) == -1) //two negative numbers so we go with right right rotation
    {
        some_node = right_right_rotate(some_node);
    }
    else if(balance_factor(some_node) < -1 && balance_factor(some_node->right) == 1) //one negative number -> right, one positive number -> left
    {
        some_node = right_left_rotate(some_node);
    }

    return some_node;
}

bool AVL::search_student(int some_id)
{
    if(size == 0)
    {
        cout << "the AVL tree is Empty!" << endl;
        return false;
    }
    else
    {
        int level = 0;
        node* current_node = root;
        while(current_node != nullptr)
        {
            if(some_id > current_node->student_data.getId())
            {
                current_node = current_node->right;
                level++;
            }
            else if (some_id < current_node->student_data.getId())
            {
                current_node = current_node->left;
                level++;
            }
            else
            {
                cout << "Student Found!" << endl;
                cout << current_node->student_data.getinfo() << endl;
                cout << level << endl;
                return true;
            }
        }

        cout << "Student Not Found!" << endl;
        return false;
    }
}

void AVL::in_order_traversal(node* some_node)
{
    if(some_node == nullptr) //base case
    {
        return;
    }

    //recursivly print the left sub tree
    in_order_traversal(some_node->left);

    cout << some_node->student_data.getinfo() << endl; //print the node it self

    //recursivly print the right sub tree
    in_order_traversal(some_node->right);
}

void AVL::delete_AVL(node* some_node)
{
    if(some_node == nullptr)
    {
        return;
    }

    delete_AVL(some_node->left);
    delete_AVL(some_node->right);
    delete some_node;
}

void AVL::print()
{
    in_order_traversal(root);
}