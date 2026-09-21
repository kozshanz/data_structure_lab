#include <iostream>

using namespace std;

int main() {
    int beds[3][3][4] = {
        { {0, 1, 0, 0}, {1, 1, 0, 1}, {0, 0, 0, 1} },
        { {1, 0, 1, 0}, {0, 0, 0, 0}, {1, 1, 1, 0} },
        { {0, 1, 1, 1}, {1, 0, 0, 1}, {0, 0, 1, 0} }
    };

    for (int i = 0; i < 3; i++) {
        cout << "Floor " << i + 1 << " status:" << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Ward " << j + 1 << ": ";
            for (int k = 0; k < 4; k++) {
                cout << beds[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int total_occupied = 0;
    int total_available = 0;
    int floor_count[3] = {0, 0, 0};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                if (beds[i][j][k] == 1) {
                    total_occupied++;
                    floor_count[i]++;
                } else if (beds[i][j][k] == 0) {
                    total_available++;
                }
            }
        }
    }

    cout << "Total occupied beds: " << total_occupied << endl;
    cout << "Total available beds: " << total_available << endl;
    cout << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Occupied beds on Floor " << i + 1 << ": " << floor_count[i] << endl;
    }
    cout << endl;

    int user_floor, user_ward, user_bed;
    
    cout << "Enter floor (1-3): ";
    cin >> user_floor;
    
    cout << "Enter ward (1-3): ";
    cin >> user_ward;
    
    cout << "Enter bed (1-4): ";
    cin >> user_bed;

    if (beds[user_floor - 1][user_ward - 1][user_bed - 1] == 1) {
        cout << "The selected bed is occupied." << endl;
    } else {
        cout << "The selected bed is available." << endl;
    }

    return 0;
}