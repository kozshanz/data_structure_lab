#include <iostream>
using namespace std;

class Node {
public:
    int productID;
    Node* left;
    Node* right;

    Node(int id) {
        productID = id;
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

    // destructor to free memory
    ~BST() {
        freeMemory(root);
    }

    void freeMemory(Node* node) {
        if (node == NULL) return;
        freeMemory(node->left);
        freeMemory(node->right);
        delete node;
    }

    Node* insert(Node* node, int id) {
        if (node == NULL)
            return new Node(id);
        if (id < node->productID)
            node->left = insert(node->left, id);
        else if (id > node->productID)
            node->right = insert(node->right, id);
        else
            cout << "Product ID " << id << " already exists!" << endl;
        return node;
    }

    void insertProduct(int id) {
        root = insert(root, id);
    }

    void searchProduct(int id) {
        Node* curr = root;
        bool found = false;

        while (curr != NULL) {
            if (id == curr->productID) {
                found = true;
                break;
            } else if (id < curr->productID) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        if (found)
            cout << "Product ID " << id << " found in inventory." << endl;
        else
            cout << "Product ID " << id << " not found in inventory." << endl;
    }

    Node* findMin(Node* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, int id) {
        if (node == NULL) {
            cout << "Product ID not found!" << endl;
            return NULL;
        }

        if (id < node->productID)
            node->left = deleteNode(node->left, id);
        else if (id > node->productID)
            node->right = deleteNode(node->right, id);
        else {
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            } else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->productID = temp->productID;
                node->right = deleteNode(node->right, temp->productID);
            }
        }
        return node;
    }

    void deleteProduct(int id) {
        root = deleteNode(root, id);
    }

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->productID << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->productID << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->productID << " ";
    }

    void displayInorder() {
        cout << "In-order: ";
        inorder(root);
        cout << endl;
    }

    void displayPreorder() {
        cout << "Pre-order: ";
        preorder(root);
        cout << endl;
    }

    void displayPostorder() {
        cout << "Post-order: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    BST store;
    int choice, id;

    do {
        cout << "\n--- Online Store Inventory ---" << endl;
        cout << "1. Insert a product ID" << endl;
        cout << "2. Search for a product ID" << endl;
        cout << "3. Delete a product ID" << endl;
        cout << "4. Display in-order traversal" << endl;
        cout << "5. Display pre-order traversal" << endl;
        cout << "6. Display post-order traversal" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter product ID to insert: ";
            cin >> id;
            store.insertProduct(id);
            break;
        case 2:
            cout << "Enter product ID to search: ";
            cin >> id;
            store.searchProduct(id);
            break;
        case 3:
            cout << "Enter product ID to delete: ";
            cin >> id;
            store.deleteProduct(id);
            break;
        case 4:
            store.displayInorder();
            break;
        case 5:
            store.displayPreorder();
            break;
        case 6:
            store.displayPostorder();
            break;
        case 7:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
