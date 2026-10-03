#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    Patient* next;

    Patient(int id, string name, int age) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->next = nullptr;
    }
};

class HospitalList {
private:
    Patient* head;

public:
    HospitalList() {
        head = nullptr;
    }

    void addAtEnd(int id, string name, int age) {
        Patient* newNode = new Patient(id, name, age);
        if (head == nullptr) {
            head = newNode;
            cout << "Patient added at end.\n";
            return;
        }
        Patient* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        cout << "Patient added at end.\n";
    }

    void addAtBeginning(int id, string name, int age) {
        Patient* newNode = new Patient(id, name, age);
        newNode->next = head;
        head = newNode;
        cout << "Emergency patient added at beginning.\n";
    }

    void search(int id) {
        Patient* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "Patient Found -> ID: " << temp->id
                     << ", Name: " << temp->name
                     << ", Age: " << temp->age << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Patient not found.\n";
    }

    void removePatient(int id) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->id == id) {
            Patient* del = head;
            head = head->next;
            delete del;
            cout << "Patient removed.\n";
            return;
        }
        Patient* temp = head;
        while (temp->next != nullptr && temp->next->id != id)
            temp = temp->next;
        if (temp->next == nullptr) {
            cout << "Patient not found.\n";
            return;
        }
        Patient* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Patient removed.\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "No patients in the waiting list.\n";
            return;
        }
        cout << "Waiting Patients:\n";
        Patient* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Age: " << temp->age << "\n";
            temp = temp->next;
        }
    }

    ~HospitalList() {
        Patient* temp = head;
        while (temp != nullptr) {
            Patient* del = temp;
            temp = temp->next;
            delete del;
        }
    }
};

int main() {
    HospitalList hospital;
    int choice;
    do {
        cout << "\n===== Hospital Emergency Management =====\n";
        cout << "1. Add Patient at End\n";
        cout << "2. Add Emergency Patient at Beginning\n";
        cout << "3. Search Patient by ID\n";
        cout << "4. Remove Patient by ID\n";
        cout << "5. Display All Patients\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, age; string name;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Age: "; cin >> age;
            hospital.addAtEnd(id, name, age);
        } else if (choice == 2) {
            int id, age; string name;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Age: "; cin >> age;
            hospital.addAtBeginning(id, name, age);
        } else if (choice == 3) {
            int id;
            cout << "Enter Patient ID: "; cin >> id;
            hospital.search(id);
        } else if (choice == 4) {
            int id;
            cout << "Enter Patient ID to remove: "; cin >> id;
            hospital.removePatient(id);
        } else if (choice == 5) {
            hospital.display();
        } else if (choice != 6) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
