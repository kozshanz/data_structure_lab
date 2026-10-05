#include <iostream>
#include <string>
using namespace std;

class Player {
public:
    string name;
    Player* next;

    Player(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class GameTurns {
private:
    Player* head;
    Player* tail;

public:
    GameTurns() {
        head = nullptr;
        tail = nullptr;
    }

    void addPlayer(string name) {
        Player* newNode = new Player(name);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }

    void displayTurns() {
        if (head == nullptr) {
            cout << "No players in the game." << endl;
            return;
        }
        cout << "Player Turns (One Round):" << endl;
        Player* temp = head;
        int count = 1;
        do {
            cout << "Turn " << count << ": " << temp->name << endl;
            count++;
            temp = temp->next;
        } while (temp != head);
    }

    void showCircularConnection() {
        if (head == nullptr) {
            cout << "No players in the game." << endl;
            return;
        }
        cout << "Circular Connection Demo:" << endl;
        cout << "After last player (" << tail->name << "), next turn goes back to: " << tail->next->name << endl;
    }

    ~GameTurns() {
        if (head == nullptr)
            return;
        tail->next = nullptr;
        Player* temp = head;
        while (temp != nullptr) {
            Player* del = temp;
            temp = temp->next;
            delete del;
        }
    }
};

int main() {
    GameTurns game;
    string name;

    cout << "Enter 5 player names:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "Player " << i << ": ";
        cin >> name;
        game.addPlayer(name);
    }

    cout << endl;
    game.displayTurns();
    cout << endl;
    game.showCircularConnection();

    return 0;
}
