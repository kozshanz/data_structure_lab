#include <iostream>
using namespace std;

const int SIZE = 5;

class CircularQueue {
    int arr[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(int packet) {
        if (count == SIZE) {
            cout << "Queue is full!\n";
            return;
        }

        rear = (rear + 1) % SIZE;
        arr[rear] = packet;
        count++;

        cout << "Packet " << packet << " added.\n";
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "Transmitting packet: " << arr[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "No packets waiting.\n";
            return;
        }

        cout << "Packets waiting: ";

        for (int i = 0; i < count; i++)
            cout << arr[(front + i) % SIZE] << " ";

        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, packet;

    do {
        cout << "\n1. Add Packet\n2. Transmit Packet\n3. Display Packets\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter packet ID: ";
                cin >> packet;
                q.enqueue(packet);
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