#include <iostream>
#include <string>
using namespace std;

// node to store a person
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

// display each person and their children
void displayTree(Node* root) {
    if (root == NULL)
        return;

    cout << "Name: " << root->name;

    if (root->left != NULL)
        cout << "  |  Left child: " << root->left->name;
    else
        cout << "  |  Left child: None";

    if (root->right != NULL)
        cout << "  |  Right child: " << root->right->name;
    else
        cout << "  |  Right child: None";

    cout << endl;

    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    // create 7 family members
    Node* root = new Node("Grandfather");

    root->left = new Node("Father");
    root->right = new Node("Uncle");

    root->left->left = new Node("Son1");
    root->left->right = new Node("Son2");

    root->right->left = new Node("Cousin1");
    root->right->right = new Node("Cousin2");

    cout << "--- Family Tree ---" << endl;
    displayTree(root);

    return 0;
}
