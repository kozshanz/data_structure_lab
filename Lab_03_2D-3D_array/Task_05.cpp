#include <iostream>

using namespace std;

int main() {
    int labs[2][3][5] = {
        {
            {0, 1, 0, 0, 1},
            {1, 1, 0, 0, 0},
            {0, 0, 1, 1, 0}
        },
        {
            {1, 0, 0, 1, 1},
            {0, 0, 0, 0, 0},
            {1, 1, 0, 1, 0}
        }
    };

    for (int i = 0; i < 2; i++) {
        cout << "Lab " << i + 1 << " status:" << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Row " << j + 1 << ": ";
            for (int k = 0; k < 5; k++) {
                cout << labs[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int total_available = 0;
    int total_in_use = 0;
    int lab_available[2] = {0, 0};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 5; k++) {
                if (labs[i][j][k] == 0) {
                    total_available++;
                    lab_available[i]++;
                } else if (labs[i][j][k] == 1) {
                    total_in_use++;
                }
            }
        }
    }

    cout << "Total available computers: " << total_available << endl;
    cout << "Total computers in use: " << total_in_use << endl;
    cout << endl;

    for (int i = 0; i < 2; i++) {
        cout << "Available computers in Lab " << i + 1 << ": " << lab_available[i] << endl;
    }
    cout << endl;

    int user_lab, user_row, user_comp;
    
    cout << "Enter lab (1-2): ";
    cin >> user_lab;
    
    cout << "Enter row (1-3): ";
    cin >> user_row;
    
    cout << "Enter computer (1-5): ";
    cin >> user_comp;

    if (labs[user_lab - 1][user_row - 1][user_comp - 1] == 0) {
        cout << "The selected computer is available." << endl;
    } else {
        cout << "The selected computer is in use." << endl;
    }

    return 0;
}