#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string c) {
        category = c;
        left = NULL;
        right = NULL;
    }
};

void bfs(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr->category << " -> ";

        if (curr->left != NULL) {
            q.push(curr->left);
        }

        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }

    cout << "END" << endl;
}

int main() {
    Node* root = new Node("Shopping");
    Node* n1 = new Node("Electronics");
    Node* n2 = new Node("Clothing");
    Node* n3 = new Node("Mobiles");
    Node* n4 = new Node("Laptops");
    Node* n5 = new Node("Men");
    Node* n6 = new Node("Women");
    Node* n7 = new Node("Accessories");

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = n5;
    n2->right = n6;

    n3->left = n7;

    cout << "Online Shopping Categories (BFS Traversal):" << endl;
    bfs(root);

    return 0;
}
