#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5;

class Patient {
public:
    string id;
    int priority;
};

class PriorityQueue {
    Patient arr[SIZE];
    int count;

public:
    PriorityQueue() {
        count = 0;
    }

    void enqueue(string id, int priority) {
        if (count == SIZE) {
            cout << "Queue is full!\n";
            return;
        }

        int i = count - 1;

        while (i >= 0 && arr[i].priority > priority) {
            arr[i + 1] = arr[i];
            i--;
        }

        arr[i + 1].id = id;
        arr[i + 1].priority = priority;
        count++;

        cout << "Patient added successfully.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "Treating patient: " << arr[0].id
             << " with priority " << arr[0].priority << endl;

        for (int i = 0; i < count - 1; i++)
            arr[i] = arr[i + 1];

        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "Waiting patients:\n";

        for (int i = 0; i < count; i++)
            cout << "Patient ID: " << arr[i].id
                 << ", Priority: " << arr[i].priority << endl;
    }
};

int main() {
    PriorityQueue q;
    int choice, priority;
    string id;

    do {
        cout << "\n1. Add Patient\n2. Treat Patient\n3. Display Patients\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter patient ID: ";
                cin >> id;
                cout << "Enter priority (1 is highest): ";
                cin >> priority;

                if (priority < 1) {
                    cout << "Invalid priority!\n";
                    break;
                }

                q.enqueue(id, priority);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}