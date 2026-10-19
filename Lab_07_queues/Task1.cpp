#include <iostream>
using namespace std;

const int SIZE = 5;

class LinearQueue {
    int arr[SIZE];
    int front, rear;

public:
    LinearQueue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int token) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow!\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = token;
        cout << "Customer " << token << " added.\n";
    }

    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow! No customers waiting.\n";
            return;
        }

        cout << "Serving customer: " << arr[front] << endl;
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (front == -1) {
            cout << "No customers waiting.\n";
            return;
        }

        cout << "Waiting customers: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";

        cout << endl;
    }

    void count() {
        if (front == -1)
            cout << "Waiting customers: 0\n";
        else
            cout << "Waiting customers: " << rear - front + 1 << endl;
    }
};

int main() {
    LinearQueue q;
    int choice, token;

    do {
        cout << "\n1. Add Customer\n2. Serve Customer\n3. Display Customers\n4. Count Customers\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter token number: ";
                cin >> token;
                q.enqueue(token);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.count();
                break;
            case 5:
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}