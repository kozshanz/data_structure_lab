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

    void inserttotail(int roll) {
        node* newnode = new node(roll);
        if (head == NULL) {
            head = newnode;
            tail = head;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void display() {
        cout << "Registered Students:" << endl;
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
    linkedlist list;
    
    while (true) {
        int choice;
        cout << "\n====Student Registration System====" << endl;
        cout << "Enter your choice: " << endl;
        cout << "1. Add a new student." << endl;
        cout << "2. Display all students." << endl;
        cout << "3. Search the student." << endl;
        cout << "4. Exit." << endl;
        cin >> choice;

        if (choice == 1) {
            int roll;
            cout << "Enter Roll Number: ";
            cin >> roll;
            list.inserttotail(roll);
        }
        else if (choice == 2) {
            list.display();
        }
        else if (choice == 3) {
            int roll;
            cout << "Enter Roll Number to Search: ";
            cin >> roll;
            list.search(roll);
        }
        else if (choice == 4) {
            break;
        }
        else {
            return 0;
        }
    }
    
    return 0;
}