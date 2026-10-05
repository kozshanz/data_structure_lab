#include <iostream>
#include <string>
using namespace std;

class Image {
public:
    string name;
    Image* prev;
    Image* next;

    Image(string name) {
        this->name = name;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class ImageGallery {
private:
    Image* head;
    Image* tail;

public:
    ImageGallery() {
        head = nullptr;
        tail = nullptr;
    }

    void addImage(string name) {
        Image* newNode = new Image(name);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void displayForward() {
        if (head == nullptr) {
            cout << "Gallery is empty." << endl;
            return;
        }
        cout << "Images (First -> Last):" << endl;
        Image* temp = head;
        while (temp != nullptr) {
            cout << " [" << temp->name << "]";
            if (temp->next != nullptr)
                cout << " --> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        if (tail == nullptr) {
            cout << "Gallery is empty." << endl;
            return;
        }
        cout << "Images (Last -> First):" << endl;
        Image* temp = tail;
        while (temp != nullptr) {
            cout << " [" << temp->name << "]";
            if (temp->prev != nullptr)
                cout << " --> ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void demonstrateNavigation() {
        if (head == nullptr || head->next == nullptr) {
            cout << "Not enough images to demonstrate navigation." << endl;
            return;
        }

        cout << "Navigation Demo (using prev and next):" << endl;

        Image* current = head;
        cout << "Starting at: " << current->name << endl;

        current = current->next;
        cout << "Moved NEXT to: " << current->name << endl;

        current = current->next;
        cout << "Moved NEXT to: " << current->name << endl;

        current = current->prev;
        cout << "Moved PREV to: " << current->name << endl;

        current = current->prev;
        cout << "Moved PREV to: " << current->name << endl;
    }

    ~ImageGallery() {
        Image* temp = head;
        while (temp != nullptr) {
            Image* del = temp;
            temp = temp->next;
            delete del;
        }
    }
};

int main() {
    ImageGallery gallery;
    string name;

    cout << "Enter 5 image names for your gallery:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "Image " << i << ": ";
        cin >> name;
        gallery.addImage(name);
    }

    cout << endl;
    gallery.displayForward();
    cout << endl;
    gallery.displayBackward();
    cout << endl;
    gallery.demonstrateNavigation();

    return 0;
}
