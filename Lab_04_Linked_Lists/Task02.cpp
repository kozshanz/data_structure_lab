#include <iostream>
#include <string>

using namespace std;

class node {
public:
    string patientID;
    node* next;

    node() {
        patientID = "";
        next = NULL;
    }

    node(string id) {
        patientID = id;
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

    void addPatient(string id) {
        node* newnode = new node(id);
        if (head == NULL) {
            head = newnode;
            tail = head;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "No patients in queue." << endl;
            return;
        }
        cout << "Waiting Patients:" << endl;
        node* temp = head;
        while (temp != NULL) {
            cout << temp->patientID;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void servePatient() {
        if (head == NULL) {
            cout << "No patients to serve." << endl;
            return;
        }
        node* temp = head;
        cout << "Patient " << head->patientID << " is being served." << endl;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
    }
};

int main() {
    linkedlist queue;

    while (true) {
        int choice;
        cout << "\n====Hospital Patient Queue====" << endl;
        cout << "Enter your choice: " << endl;
        cout << "1. Add a new patient." << endl;
        cout << "2. Display waiting patients." << endl;
        cout << "3. Serve patient." << endl;
        cout << "4. Exit." << endl;
        cin >> choice;

        if (choice == 1) {
            string id;
            cout << "Enter Patient ID: ";
            cin >> id;
            queue.addPatient(id);
        }
        else if (choice == 2) {
            queue.display();
        }
        else if (choice == 3) {
            queue.servePatient();
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