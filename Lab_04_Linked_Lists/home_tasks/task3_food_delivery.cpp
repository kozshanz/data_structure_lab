#include <iostream>
#include <string>
using namespace std;

class Order {
public:
    int orderId;
    string customerName;
    string foodItem;
    Order* next;

    Order(int orderId, string customerName, string foodItem) {
        this->orderId = orderId;
        this->customerName = customerName;
        this->foodItem = foodItem;
        this->next = nullptr;
    }
};

class DeliveryList {
private:
    Order* head;

public:
    DeliveryList() {
        head = nullptr;
    }

    void addAtEnd(int id, string name, string item) {
        Order* newNode = new Order(id, name, item);
        if (head == nullptr) {
            head = newNode;
            cout << "Order added at end.\n";
            return;
        }
        Order* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        cout << "Order added at end.\n";
    }

    void addAtBeginning(int id, string name, string item) {
        Order* newNode = new Order(id, name, item);
        newNode->next = head;
        head = newNode;
        cout << "Urgent Order " << id << " received.\n";
    }

    void display() {
        if (head == nullptr) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "Pending Orders:\n";
        Order* temp = head;
        while (temp != nullptr) {
            cout << "0" << temp->orderId;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << "\n";
    }

    void searchOrder(int id) {
        Order* temp = head;
        while (temp != nullptr) {
            if (temp->orderId == id) {
                cout << "Order Found -> ID: 0" << temp->orderId
                     << ", Customer: " << temp->customerName
                     << ", Item: " << temp->foodItem << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Order not found.\n";
    }

    void removeOrder(int id) {
        if (head == nullptr) {
            cout << "No orders to remove.\n";
            return;
        }
        if (head->orderId == id) {
            Order* del = head;
            head = head->next;
            cout << "Order 0" << id << " delivered.\n";
            delete del;
            return;
        }
        Order* temp = head;
        while (temp->next != nullptr && temp->next->orderId != id)
            temp = temp->next;
        if (temp->next == nullptr) {
            cout << "Order not found.\n";
            return;
        }
        Order* del = temp->next;
        temp->next = del->next;
        cout << "Order 0" << id << " delivered.\n";
        delete del;
    }

    ~DeliveryList() {
        Order* temp = head;
        while (temp != nullptr) {
            Order* del = temp;
            temp = temp->next;
            delete del;
        }
    }
};

int main() {
    DeliveryList delivery;
    int choice;
    do {
        cout << "\n===== Online Food Delivery System =====\n";
        cout << "1. Add Order at End\n";
        cout << "2. Display Pending Orders\n";
        cout << "3. Search Order by ID\n";
        cout << "4. Remove Order (Delivered)\n";
        cout << "5. Add Urgent Order at Beginning\n";
        cout << "6. Display Updated Pending Orders\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id; string name, item;
            cout << "Enter Order ID: "; cin >> id;
            cout << "Enter Customer Name: "; cin >> name;
            cout << "Enter Food Item: "; cin >> item;
            delivery.addAtEnd(id, name, item);
        } else if (choice == 2) {
            delivery.display();
        } else if (choice == 3) {
            int id;
            cout << "Enter Order ID: "; cin >> id;
            delivery.searchOrder(id);
        } else if (choice == 4) {
            int id;
            cout << "Enter Order ID to remove: "; cin >> id;
            delivery.removeOrder(id);
        } else if (choice == 5) {
            int id; string name, item;
            cout << "Enter Order ID: "; cin >> id;
            cout << "Enter Customer Name: "; cin >> name;
            cout << "Enter Food Item: "; cin >> item;
            delivery.addAtBeginning(id, name, item);
        } else if (choice == 6) {
            delivery.display();
        } else if (choice != 7) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 7);

    return 0;
}
