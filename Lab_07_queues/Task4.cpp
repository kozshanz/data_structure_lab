#include <iostream>
using namespace std;

const int SIZE = 5;

class Deque {
    int arr[SIZE];
    int front, rear, count;

public:
    Deque() {
        front = -1;
        rear = -1;
        count = 0;
    }

    void insertFront(int id) {
        if (count == SIZE) {
            cout << "Deque is full!\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            front = (front - 1 + SIZE) % SIZE;
        }

        arr[front] = id;
        count++;

        cout << "Request " << id << " added at front.\n";
    }

    void insertRear(int id) {
        if (count == SIZE) {
            cout << "Deque is full!\n";
            return;
        }

        if (count == 0) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        arr[rear] = id;
        count++;

        cout << "Request " << id << " added at rear.\n";
    }

    void deleteFront() {
        if (count == 0) {
            cout << "Deque is empty!\n";
            return;
        }

        cout << "Removed request: " << arr[front] << endl;

        if (count == 1) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }

        count--;
    }

    void deleteRear() {
        if (count == 0) {
            cout << "Deque is empty!\n";
            return;
        }

        cout << "Removed request: " << arr[rear] << endl;

        if (count == 1) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + SIZE) % SIZE;
        }

        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No passenger requests.\n";
            return;
        }

        cout << "Requests from front to rear: ";

        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % SIZE] << " ";

        cout << endl;
    }
};

int main() {
    Deque d;
    int choice, id;

    do {
        cout << "\n1. Insert at Front\n2. Insert at Rear\n";
        cout << "3. Remove from Front\n4. Remove from Rear\n";
        cout << "5. Display Requests\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter passenger request ID: ";
                cin >> id;
                d.insertFront(id);
                break;
            case 2:
                cout << "Enter passenger request ID: ";
                cin >> id;
                d.insertRear(id);
                break;
            case 3:
                d.deleteFront();
                break;
            case 4:
                d.deleteRear();
                break;
            case 5:
                d.display();
                break;
            case 6:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}