#include <iostream>
#include <string>

using namespace std;

class node {
public:
    string productID;
    node* next;

    node() {
        productID = "";
        next = NULL;
    }

    node(string id) {
        productID = id;
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

    void addProduct(string id) {
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
            cout << "Shopping cart is empty." << endl;
            return;
        }
        cout << "Shopping Cart:" << endl;
        node* temp = head;
        while (temp != NULL) {
            cout << temp->productID;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void removeProduct(string id) {
        if (head == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }

        if (head->productID == id) {
            node* temp = head;
            head = head->next;
            if (head == NULL) {
                tail = NULL;
            }
            delete temp;
            cout << "Product " << id << " removed." << endl;
            return;
        }

        node* current = head;
        while (current->next != NULL && current->next->productID != id) {
            current = current->next;
        }

        if (current->next != NULL) {
            node* temp = current->next;
            current->next = current->next->next;
            if (current->next == NULL) {
                tail = current;
            }
            delete temp;
            cout << "Product " << id << " removed." << endl;
        } else {
            cout << "Product Not Found" << endl;
        }
    }
};

int main() {
    linkedlist cart;

    while (true) {
        int choice;
        cout << "\n====Online Shopping Cart====" << endl;
        cout << "Enter your choice: " << endl;
        cout << "1. Add a product." << endl;
        cout << "2. Display cart." << endl;
        cout << "3. Remove a product." << endl;
        cout << "4. Exit." << endl;
        cin >> choice;

        if (choice == 1) {
            string id;
            cout << "Enter Product ID: ";
            cin >> id;
            cart.addProduct(id);
        }
        else if (choice == 2) {
            cart.display();
        }
        else if (choice == 3) {
            string id;
            cout << "Enter Product ID to Remove: ";
            cin >> id;
            cart.removeProduct(id);
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