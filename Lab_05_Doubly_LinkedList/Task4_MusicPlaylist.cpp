#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string title;
    Song* next;

    Song(string title) {
        this->title = title;
        this->next = nullptr;
    }
};

class MusicPlaylist {
private:
    Song* head;
    Song* tail;
    int size;

public:
    MusicPlaylist() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void addSong(string title) {
        Song* newNode = new Song(title);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            tail->next = head;
            size++;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
        size++;
    }

    void displayAllSongs() {
        if (head == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }
        cout << "Playlist (All Songs):" << endl;
        Song* temp = head;
        int count = 1;
        do {
            cout << count << ". " << temp->title << endl;
            count++;
            temp = temp->next;
        } while (temp != head);
    }

    void playTwoRounds() {
        if (head == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }
        cout << "Simulating 2 Complete Rounds:" << endl;
        Song* temp = head;
        for (int round = 1; round <= 2; round++) {
            cout << "--- Round " << round << " ---" << endl;
            int count = 1;
            do {
                cout << "Now Playing: " << temp->title << endl;
                temp = temp->next;
                count++;
            } while (count <= size);
        }
        cout << "After Round 2, playlist continues from: " << head->title << endl;
    }

    ~MusicPlaylist() {
        if (head == nullptr)
            return;
        tail->next = nullptr;
        Song* temp = head;
        while (temp != nullptr) {
            Song* del = temp;
            temp = temp->next;
            delete del;
        }
    }
};

int main() {
    MusicPlaylist playlist;
    string title;

    cout << "Enter 5 song names for your playlist:" << endl;
    for (int i = 1; i <= 5; i++) {
        cout << "Song " << i << ": ";
        getline(cin, title);
        playlist.addSong(title);
    }

    cout << endl;
    playlist.displayAllSongs();
    cout << endl;
    playlist.playTwoRounds();

    return 0;
}
