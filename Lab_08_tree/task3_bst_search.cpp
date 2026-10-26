#include <iostream>
using namespace std;

class Node {
public:
    int bookID;
    Node* left;
    Node* right;

    Node(int id) {
        bookID = id;
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

    Node* insert(Node* node, int id) {
        if (node == NULL)
            return new Node(id);

        if (id < node->bookID)
            node->left = insert(node->left, id);
        else if (id > node->bookID)
            node->right = insert(node->right, id);

        return node;
    }

    void insert(int id) {
        root = insert(root, id);
    }

    // search and count comparisons
    void search(int id) {
        Node* curr = root;
        int comparisons = 0;
        bool found = false;

        while (curr != NULL) {
            comparisons++;

            if (id == curr->bookID) {
                found = true;
                break;
            } else if (id < curr->bookID) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (found)
            cout << "Book Found!" << endl;
        else
            cout << "Book Not Found!" << endl;

        cout << "Comparisons made: " << comparisons << endl;
    }
};

int main() {
    BST tree;

    // insert book IDs
    int ids[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) {
        tree.insert(ids[i]);
    }

    int searchID;
    cout << "Enter book ID to search: ";
    cin >> searchID;

    tree.search(searchID);

    return 0;
}
