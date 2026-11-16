#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = NULL;
        right = NULL;
    }
};

void display(Node* temp) {
    if (temp == NULL) {
        return;
    }

    cout << "Member: " << temp->name << endl;

    if (temp->left != NULL) {
        cout << "  Left Child: " << temp->left->name << endl;
    } else {
        cout << "  Left Child: None" << endl;
    }

    if (temp->right != NULL) {
        cout << "  Right Child: " << temp->right->name << endl;
    } else {
        cout << "  Right Child: None" << endl;
    }

    cout << endl;

    display(temp->left);
    display(temp->right);
}

int main() {
    Node* root = new Node("Dr. Ahmed (HOD)");
    Node* c1 = new Node("Prof. Sara (Coordinator)");
    Node* c2 = new Node("Prof. Bilal (Coordinator)");
    Node* f1 = new Node("Mr. Ali (Faculty)");
    Node* f2 = new Node("Ms. Ayesha (Faculty)");
    Node* f3 = new Node("Mr. Usman (Faculty)");
    Node* f4 = new Node("Ms. Hina (Faculty)");

    root->left = c1;
    root->right = c2;

    c1->left = f1;
    c1->right = f2;

    c2->left = f3;
    c2->right = f4;

    cout << "University Department Hierarchy:" << endl << endl;
    display(root);

    return 0;
}
