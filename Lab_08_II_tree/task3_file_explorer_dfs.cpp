#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string f) {
        folder = f;
        left = NULL;
        right = NULL;
    }
};

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->folder << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->folder << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->folder << " ";
}

int main() {
    Node* root = new Node("C_Drive");
    Node* f1 = new Node("Documents");
    Node* f2 = new Node("Downloads");
    Node* f3 = new Node("Work");
    Node* f4 = new Node("Personal");
    Node* f5 = new Node("Software");
    Node* f6 = new Node("Movies");

    root->left = f1;
    root->right = f2;

    f1->left = f3;
    f1->right = f4;

    f2->left = f5;
    f2->right = f6;

    cout << "Pre-order Traversal (Root -> Left -> Right):" << endl;
    preOrder(root);
    cout << endl << endl;

    cout << "In-order Traversal (Left -> Root -> Right):" << endl;
    inOrder(root);
    cout << endl << endl;

    cout << "Post-order Traversal (Left -> Right -> Root):" << endl;
    postOrder(root);
    cout << endl;

    return 0;
}
