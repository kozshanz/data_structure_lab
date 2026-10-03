#include <iostream>
#include <string>
using namespace std;

class Course {
public:
    string code;
    string name;
    int creditHours;
    Course* next;

    Course(string code, string name, int creditHours) {
        this->code = code;
        this->name = name;
        this->creditHours = creditHours;
        this->next = nullptr;
    }
};

class CourseList {
private:
    Course* head;

public:
    CourseList() {
        head = nullptr;
    }

    void addAtBeginning(string code, string name, int credits) {
        Course* newNode = new Course(code, name, credits);
        newNode->next = head;
        head = newNode;
        cout << "Course added at beginning.\n";
    }

    void addAtEnd(string code, string name, int credits) {
        Course* newNode = new Course(code, name, credits);
        if (head == nullptr) {
            head = newNode;
            cout << "Course added at end.\n";
            return;
        }
        Course* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        cout << "Course added at end.\n";
    }

    void searchCourse(string code) {
        Course* temp = head;
        while (temp != nullptr) {
            if (temp->code == code) {
                cout << "Course Found -> Code: " << temp->code
                     << ", Name: " << temp->name
                     << ", Credits: " << temp->creditHours << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Course not found.\n";
    }

    void deleteCourse(string code) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->code == code) {
            Course* del = head;
            head = head->next;
            delete del;
            cout << "Course deleted.\n";
            return;
        }
        Course* temp = head;
        while (temp->next != nullptr && temp->next->code != code)
            temp = temp->next;
        if (temp->next == nullptr) {
            cout << "Course not found.\n";
            return;
        }
        Course* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Course deleted.\n";
    }

    void displayAll() {
        if (head == nullptr) {
            cout << "No courses in the list.\n";
            return;
        }
        Course* temp = head;
        while (temp != nullptr) {
            cout << temp->code;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << "\n";
    }

    int countCourses() {
        int count = 0;
        Course* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void concatenate(CourseList& other) {
        if (other.head == nullptr) return;
        if (head == nullptr) {
            head = other.head;
            other.head = nullptr;
            return;
        }
        Course* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = other.head;
        other.head = nullptr;
        cout << "Lists concatenated.\n";
    }

    ~CourseList() {
        Course* temp = head;
        while (temp != nullptr) {
            Course* del = temp;
            temp = temp->next;
            delete del;
        }
    }
};

int main() {
    CourseList courses;
    int choice;
    do {
        cout << "\n===== University Course Management =====\n";
        cout << "1. Add Course at Beginning\n";
        cout << "2. Add Course at End\n";
        cout << "3. Search Course\n";
        cout << "4. Delete Course\n";
        cout << "5. Display All Courses\n";
        cout << "6. Count Total Courses\n";
        cout << "7. Concatenate Another Course List\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string code, name; int credits;
            cout << "Enter Course Code: "; cin >> code;
            cout << "Enter Course Name: "; cin >> name;
            cout << "Enter Credit Hours: "; cin >> credits;
            courses.addAtBeginning(code, name, credits);
        } else if (choice == 2) {
            string code, name; int credits;
            cout << "Enter Course Code: "; cin >> code;
            cout << "Enter Course Name: "; cin >> name;
            cout << "Enter Credit Hours: "; cin >> credits;
            courses.addAtEnd(code, name, credits);
        } else if (choice == 3) {
            string code;
            cout << "Enter Course Code: "; cin >> code;
            courses.searchCourse(code);
        } else if (choice == 4) {
            string code;
            cout << "Enter Course Code to delete: "; cin >> code;
            courses.deleteCourse(code);
        } else if (choice == 5) {
            cout << "Course List: ";
            courses.displayAll();
        } else if (choice == 6) {
            cout << "Total Courses: " << courses.countCourses() << "\n";
        } else if (choice == 7) {
            CourseList secondList;
            int n;
            cout << "How many courses in the second list? "; cin >> n;
            for (int i = 0; i < n; i++) {
                string code, name; int credits;
                cout << "Enter Course Code: "; cin >> code;
                cout << "Enter Course Name: "; cin >> name;
                cout << "Enter Credit Hours: "; cin >> credits;
                secondList.addAtEnd(code, name, credits);
            }
            courses.concatenate(secondList);
            cout << "Combined Course List: ";
            courses.displayAll();
        } else if (choice != 8) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 8);

    return 0;
}
