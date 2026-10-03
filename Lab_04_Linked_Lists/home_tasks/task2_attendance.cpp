#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    string status;
    Student* next;

    Student(int rollNo, string name, string status) {
        this->rollNo = rollNo;
        this->name = name;
        this->status = status;
        this->next = nullptr;
    }
};

class AttendanceList {
private:
    Student* head;

public:
    AttendanceList() {
        head = nullptr;
    }

    void addStudent(int rollNo, string name, string status) {
        Student* newNode = new Student(rollNo, name, status);
        if (head == nullptr) {
            head = newNode;
            cout << "Student added.\n";
            return;
        }
        Student* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        cout << "Student added.\n";
    }

    void searchStudent(int rollNo) {
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->rollNo == rollNo) {
                cout << "Found -> Roll No: " << temp->rollNo
                     << ", Name: " << temp->name
                     << ", Status: " << temp->status << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found.\n";
    }

    void deleteStudent(int rollNo) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->rollNo == rollNo) {
            Student* del = head;
            head = head->next;
            delete del;
            cout << "Student deleted.\n";
            return;
        }
        Student* temp = head;
        while (temp->next != nullptr && temp->next->rollNo != rollNo)
            temp = temp->next;
        if (temp->next == nullptr) {
            cout << "Student not found.\n";
            return;
        }
        Student* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Student deleted.\n";
    }

    void displayAll() {
        if (head == nullptr) {
            cout << "No students in the list.\n";
            return;
        }
        cout << "Attendance List:\n";
        Student* temp = head;
        while (temp != nullptr) {
            cout << "Roll No: " << temp->rollNo
                 << " | Name: " << temp->name
                 << " | Status: " << temp->status << "\n";
            temp = temp->next;
        }
    }

    void countPresent() {
        int count = 0;
        Student* temp = head;
        while (temp != nullptr) {
            if (temp->status == "Present" || temp->status == "present")
                count++;
            temp = temp->next;
        }
        cout << "Total students present: " << count << "\n";
    }

    ~AttendanceList() {
        Student* temp = head;
        while (temp != nullptr) {
            Student* del = temp;
            temp = temp->next;
            delete del;
        }
    }
};

int main() {
    AttendanceList attendance;
    int choice;
    do {
        cout << "\n===== University Attendance System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student by Roll Number\n";
        cout << "3. Delete Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Count Students Present\n";
        cout << "6. Display Final Attendance List\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll; string name, status;
            cout << "Enter Roll No: "; cin >> roll;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Status (Present/Absent): "; cin >> status;
            attendance.addStudent(roll, name, status);
        } else if (choice == 2) {
            int roll;
            cout << "Enter Roll No: "; cin >> roll;
            attendance.searchStudent(roll);
        } else if (choice == 3) {
            int roll;
            cout << "Enter Roll No: "; cin >> roll;
            attendance.deleteStudent(roll);
        } else if (choice == 4) {
            attendance.displayAll();
        } else if (choice == 5) {
            attendance.countPresent();
        } else if (choice == 6) {
            attendance.displayAll();
        } else if (choice != 7) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
