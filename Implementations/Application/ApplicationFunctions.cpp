// FCAI - Data Structures - 2023 - Assignment 1
// Program Name: Trees
// Last Modification Date:
// Author1 and ID and Group: Youssef Mohamed Salah Eldin Anwar    ID:20210483       Group: S25,26
// Author2 and ID and Group: Abdelrahman Wael Mohammed Hanafy     ID: 20210490      Group: S25,26
// Author3 and ID and Group: Basmala Mohamed Sayed Gad            ID: 20210090      Group: S25,26
#include "ApplicationHeader.h"

void Application :: readFile(vector<Student>& students){
    ifstream file;
    file.open("input.txt");
    if(!file.fail()){
        string line;
        int number;
        getline(file,line);
        number = stoi(line);

        for (int i = 0; i < number; ++i) {
            Student student;
            getline(file,line);
            student.setId(stoi(line));
            getline(file,line);
            student.setName(line);
            getline(file,line);
            student.setGPA(stod(line));
            getline(file,line);
            student.setDepartment(line);
            students.push_back(student);
        }
    }else{
        cout << "File Not Found \n";
    }
}

void Application :: BST_menu(BST& bst){
    int BSTChoice;
    int id;
    double gpa;
    string name;
    string depart;
    while (true){
        cout << "\nChoose one of the following options:\n"
                "1. Add student\n"
                "2. Remove student\n"
                "3. Search student\n"
                "4. Print All (sorted by id)\n"
                "5. Return to main menu\n"
                "Enter your choice: ";
        cin >> BSTChoice;
        switch (BSTChoice) {
            case 1:{
                cout << "Please enter student info \n";
                cout << "ID: \n";
                cin >> id;
                cout << "Name: \n";
                cin.ignore();
                getline(cin, name);
                cout << "GPA: \n";
                cin >> gpa;
                cout << "Department: \n";
                cin.ignore();
                getline(cin, depart);

                bst.add_student(name,id,gpa,depart);
                cout << "Student added successfully \2\n";
                break;
            }
            case 2:{
                cout << "Please enter the ID of the student you want to remove: \n";
                cin >> id;
                if(bst.remove_student(id))
                    cout << "Student removed successfully \2\n";
                break;
            }
            case 3:{
                cout << "Please enter the ID of the student you want to search about: \n";
                cin >> id;
                bst.search_student(id);
                break;
            }
            case 4:{
                bst.print();
                break;
            }
            case 5:{
                return;
            }
            default:{
                cout << "Please enter valid choice!\n";
                cin >> BSTChoice;
                break;
            }
        }
    }
}

void Application :: AVL_menu(AVL& avl){
    int AVLChoice;
    int id;
    double gpa;
    string name;
    string depart;
    while (true){
        cout << "\nChoose one of the following options:\n"
                "1. Add student\n"
                "2. Remove student\n"
                "3. Search student\n"
                "4. Print All (sorted by id)\n"
                "5. Return to main menu\n"
                "Enter your choice: ";
        cin >> AVLChoice;
        switch (AVLChoice) {
            case 1:{
                cout << "Please enter student info \n";
                cout << "ID: \n";
                cin >> id;
                cout << "Name: \n";
                cin.ignore();
                getline(cin,name);
                cout << "GPA: \n";
                cin >> gpa;
                cout << "Department: \n";
                cin.ignore();
                getline(cin,depart);
                Student student(id,gpa,name,depart);
                avl.insert_student(avl.get_root(),student);
                cout << "Student added successfully \2\n";
                break;
            }
            case 2:{
                cout << "Please enter the ID of the student you want to remove: \n";
                cin >> id;
                avl.delete_student(avl.get_root(),id);
                break;
            }
            case 3:{
                cout << "Please enter the ID of the student you want to search about: \n";
                cin >> id;
                avl.search_student(id);
                break;
            }
            case 4:{
                avl.print();
                break;
            }
            case 5:{
                return;
            }
            default:{
                cout << "Please enter valid choice!\n";
                cin >> AVLChoice;
                break;
            }
        }
    }
}

void Application :: MaxHeap_menu(MaxHeap& mxHeap){
    int mxHepChoice;
    while (true){
        cout << "\nChoose one of the following options:\n"
                "1. Add student\n"
                "2. Print All (sorted by gpa)\n"
                "3. Return to main menu\n"
                "Enter your choice: ";
        cin >> mxHepChoice;
        switch (mxHepChoice) {
            case 1:{
                int id;
                double gpa;
                string name;
                string depart;
                cout << "Please enter student info \n";
                cout << "ID: \n";
                cin >> id;
                cout << "Name: \n";
                cin.ignore();
                getline(cin, name);
                cout << "GPA: \n";
                cin >> gpa;
                cout << "Department: \n";
                cin.ignore();
                getline(cin,depart);
                Student student(id,gpa,name,depart);
                mxHeap.addStudent(student);
                cout << "Student added successfully \2\n";
                break;
            }
            case 2:{
                mxHeap.print();
                break;
            }
            case 3:{
                return;
            }
            default:{
                cout << "Please enter valid choice!\n";
                cin >> mxHepChoice;
                break;
            }
        }
    }
}

void Application :: MinHeap_menu(MinHeap& miHeap){
    int miHepChoice;
    while (true){
        cout << "\nChoose one of the following options:\n"
                "1. Add student\n"
                "2. Print All (sorted by gpa)\n"
                "3. Return to main menu\n"
                "Enter your choice: ";
        cin >> miHepChoice;
        switch (miHepChoice) {
            case 1:{
                int id;
                double gpa;
                string name;
                string depart;
                cout << "Please enter student info \n";
                cout << "ID: \n";
                cin >> id;
                cout << "Name: \n";
                cin.ignore();
                getline(cin,name);
                cout << "GPA: \n";
                cin >> gpa;
                cout << "Department: \n";
                cin.ignore();
                getline(cin, depart);
                Student student(id,gpa,name,depart);
                miHeap.addStudent(student);
                cout << "Student added successfully :)\n";
                break;
            }
            case 2:{
                miHeap.print();
                break;
            }
            case 3:{
                return;
            }
            default:{
                cout << "Please enter valid choice!\n";
                cin >> miHepChoice;
                break;
            }
        }
    }
}

void Application ::Application_menu() {
    int choice;
    readFile(studentsDate);
    while (true){
        cout << "\nChoose Data Structure:\n"
                "1. BST\n"
                "2. AVL\n"
                "3. Min Heap\n"
                "4. Max Heap\n"
                "5. Exit Program\n"
                "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:{
                BST bst;
                for (int i = 0; i < studentsDate.size(); ++i) {
                    bst.add_student(studentsDate[i].getName(),studentsDate[i].getId(),studentsDate[i].getGPA(),studentsDate[i].getDepartment());
                }
                BST_menu(bst);
                break;
            }
            case 2:{
                AVL avl;
                for (int i = 0; i < studentsDate.size(); ++i) {
                    avl.insert_student(avl.get_root(),studentsDate[i]);
                }
                AVL_menu(avl);
                break;
            }
            case 3:{
                MinHeap miHeap;
                for (int i = 0; i < studentsDate.size(); ++i) {
                    miHeap.addStudent(studentsDate[i]);
                }
                MinHeap_menu(miHeap);
                break;
            }
            case 4:{
                MaxHeap mxHeap;
                for (int i = 0; i < studentsDate.size(); ++i) {
                    mxHeap.addStudent(studentsDate[i]);
                }
                MaxHeap_menu(mxHeap);
                break;
            }
            case 5:{
                cout << "Thank You for using this Application \2\n";
                exit(0);
            }
            default:{
                cout << "Please enter valid choice!\n";
                cin >> choice;
                break;
            }
        }
    }
}