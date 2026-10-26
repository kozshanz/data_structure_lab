#include <iostream>
using namespace std;

class Node {
public:
    int roll;
    Node* left;
    Node* right;

    Node(int r) {
        roll = r;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // insert a roll number
    Node* insert(Node* node, int r) {
        if (node == NULL)
            return new Node(r);

        if (r < node->roll)
            node->left = insert(node->left, r);
        else if (r > node->roll)
            node->right = insert(node->right, r);

        return node;
    }

    void insert(int r) {
        root = insert(root, r);
    }

    // inorder gives sorted order
    void inorder(Node* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->roll << " ";
        inorder(node->right);
    }

    void display() {
        cout << "Roll numbers in ascending order: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // insert the given roll numbers
    int rolls[] = {45, 25, 65, 15, 35, 55, 75};
    for (int i = 0; i < 7; i++) {
        tree.insert(rolls[i]);
    }

    // ask user for 2 more
    int r1, r2;
    cout << "Enter first roll number to insert: ";
    cin >> r1;
    cout << "Enter second roll number to insert: ";
    cin >> r2;

    tree.insert(r1);
    tree.insert(r2);

    tree.display();

    return 0;
}
