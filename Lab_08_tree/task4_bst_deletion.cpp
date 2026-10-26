#include <iostream>
using namespace std;

class Node {
public:
    int id;
    Node* left;
    Node* right;

    Node(int x) {
        id = x;
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

    Node* insert(Node* node, int x) {
        if (node == NULL)
            return new Node(x);
        if (x < node->id)
            node->left = insert(node->left, x);
        else if (x > node->id)
            node->right = insert(node->right, x);
        return node;
    }

    void insert(int x) {
        root = insert(root, x);
    }

    // find smallest value in right subtree
    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int x) {
        if (node == NULL) {
            cout << "ID not found!" << endl;
            return NULL;
        }

        if (x < node->id) {
            node->left = deleteNode(node->left, x);
        } else if (x > node->id) {
            node->right = deleteNode(node->right, x);
        } else {
            // case 1: leaf node
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            // case 2: one child
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // case 3: two children
            else {
                Node* temp = findMin(node->right);
                node->id = temp->id;
                node->right = deleteNode(node->right, temp->id);
            }
        }
        return node;
    }

    void deleteEmp(int x) {
        root = deleteNode(root, x);
    }

    void inorder(Node* node) {
        if (node == NULL)
            return;
        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
    }

    void display() {
        cout << "Remaining employee IDs: ";
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;

    // insert employee IDs
    int emp[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++) {
        tree.insert(emp[i]);
    }

    cout << "Employee IDs before deletion: ";
    tree.inorder(tree.root);
    cout << endl;

    int x;
    cout << "Enter employee ID to delete: ";
    cin >> x;

    tree.deleteEmp(x);

    tree.display();

    return 0;
}
