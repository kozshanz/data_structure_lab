#include <iostream>

using namespace std;

class node {
public:
    int roll;
    node* next;

    node() {
        roll = 0;
        next = NULL;
    }

    node(int num) {
        roll = num;
        next = NULL;
    }
};

class linkedlist {
private:
    node* head;
    node* tail;

public:
    linkedlist() {
        head = NULL;
        tail = NULL;
    }

    void addStudent(int roll) {
        node* newnode = new node(roll);
        if (head == NULL) {
            head = newnode;
            tail = head;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void insertAtBeginning(int roll) {
        node* newnode = new node(roll);
        if (head == NULL) {
            head = newnode;
            tail = head;
        } else {
            newnode->next = head;
            head = newnode;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "No students enrolled." << endl;
            return;
        }
        cout << "Enrolled Students:" << endl;
        node* temp = head;
        while (temp != NULL) {
            cout << temp->roll;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void search(int roll) {
        node* temp = head;
        while (temp != NULL) {
            if (temp->roll == roll) {
                cout << "Student Found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student Not Found" << endl;
    }
};

int main() {
    linkedlist course;

    while (true) {
        int choice;
        cout << "\n====University Course Enrollment====" << endl;
        cout << "Enter your choice: " << endl;
        cout << "1. Add a student at the end." << endl;
        cout << "2. Insert a student at the beginning." << endl;
        cout << "3. Display all enrolled students." << endl;
        cout << "4. Search for a student." << endl;
        cout << "5. Exit." << endl;
        cin >> choice;

        if (choice == 1) {
            int roll;
            cout << "Enter Roll Number: ";
            cin >> roll;
            course.addStudent(roll);
        }
        else if (choice == 2) {
            int roll;
            cout << "Enter Roll Number: ";
            cin >> roll;
            course.insertAtBeginning(roll);
        }
        else if (choice == 3) {
            course.display();
        }
        else if (choice == 4) {
            int roll;
            cout << "Enter Roll Number to Search: ";
            cin >> roll;
            course.search(roll);
        }
        else if (choice == 5) {
            break;
        }
        else {
            return 0;
        }
    }

    return 0;
}