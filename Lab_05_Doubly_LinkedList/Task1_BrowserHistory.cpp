#include <iostream>
#include <string>
using namespace std;

class Page {
public:
    string url;
    Page* prev;
    Page* next;

    Page(string url) {
        this->url = url;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class BrowserHistory {
private:
    Page* head;
    Page* tail;

public:
    BrowserHistory() {
        head = nullptr;
        tail = nullptr;
    }

    void addPage(string url) {
        Page* newNode = new Page(url);
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
            cout << "No browsing history." << endl;
            return;
        }
        cout << "Browser History (First Visited -> Last Visited):" << endl;
        Page* temp = head;
        while (temp != nullptr) {
            cout << " -> " << temp->url << endl;
            temp = temp->next;
        }
    }

    void displayReverse() {
        if (tail == nullptr) {
            cout << "No browsing history." << endl;
            return;
        }
        cout << "Browser History (Last Visited -> First Visited):" << endl;
        Page* temp = tail;
        while (temp != nullptr) {
            cout << " -> " << temp->url << endl;
            temp = temp->prev;
        }
    }

    ~BrowserHistory() {
        Page* temp = head;
        while (temp != nullptr) {
            Page* del = temp;
            temp = temp->next;
            delete del;
        }
    }
};

int main() {
    BrowserHistory history;
    string url;

    cout << "Enter 5 website URLs for your browser history:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "Website " << i << ": ";
        cin >> url;
        history.addPage(url);
    }

    cout << endl;
    history.displayForward();
    cout << endl;
    history.displayReverse();

    return 0;
}
