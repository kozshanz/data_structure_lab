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

    // left root right
    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->id << " ";
        inorder(node->right);
    }

    // root left right
    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->id << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // left right root
    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->id << " ";
    }
};

int main() {
    BST tree;

    // insert patient IDs
    int ids[] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) {
        tree.insert(ids[i]);
    }

    cout << "In-order   (Left, Root, Right): ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Pre-order  (Root, Left, Right): ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Post-order (Left, Right, Root): ";
    tree.postorder(tree.root);
    cout << endl;

    cout << endl;
    cout << "In-order traversal displays IDs in ascending order." << endl;

    return 0;
}
