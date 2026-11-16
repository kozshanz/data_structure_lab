#include <iostream>
using namespace std;

class Node {
public:
    int token;
    Node* left;
    Node* right;
    int height;

    Node(int t) {
        token = t;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int getHeight(Node* n) {
    if (n == NULL) {
        return 0;
    }
    return n->height;
}

int maxVal(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int getBalance(Node* n) {
    if (n == NULL) {
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = maxVal(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = maxVal(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = maxVal(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = maxVal(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insertNode(Node* node, int token) {
    if (node == NULL) {
        return new Node(token);
    }

    if (token < node->token) {
        node->left = insertNode(node->left, token);
    } else if (token > node->token) {
        node->right = insertNode(node->right, token);
    } else {
        return node;
    }

    node->height = 1 + maxVal(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && token < node->left->token) {
        return rightRotate(node);
    }

    if (balance < -1 && token > node->right->token) {
        return leftRotate(node);
    }

    if (balance > 1 && token > node->left->token) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && token < node->right->token) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->token << " ";
    inOrder(root->right);
}

void displayTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space = space + 6;

    displayTree(root->right, space);

    cout << endl;
    for (int i = 6; i < space; i++) {
        cout << " ";
    }
    cout << root->token << "(H:" << root->height << ",BF:" << getBalance(root) << ")" << endl;

    displayTree(root->left, space);
}

int main() {
    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};
    int size = 7;

    for (int i = 0; i < size; i++) {
        root = insertNode(root, tokens[i]);
    }

    cout << "Appointment Token Numbers (In-order Traversal):" << endl;
    inOrder(root);
    cout << endl << endl;

    cout << "Final Balanced AVL Tree Structure:" << endl;
    displayTree(root, 0);

    return 0;
}
