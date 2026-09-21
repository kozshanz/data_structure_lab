#include <iostream>

using namespace std;

int main() {
    int parking[4][5] = {
        {0, 1, 0, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0}
    };

    int occupied = 0;
    int empty = 0;

    cout << "--- Parking Layout ---\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            cout << parking[i][j] << " ";
            if (parking[i][j] == 1) {
                occupied++;
            } else {
                empty++;
            }
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "Total occupied spaces: " << occupied << "\n";
    cout << "Total empty spaces: " << empty << "\n\n";

    int row, col;
    cout << "Enter row number (1 to 4): ";
    cin >> row;
    cout << "Enter column number (1 to 5): ";
    cin >> col;

    if (parking[row - 1][col - 1] == 0) {
        cout << "Status: The selected space is AVAILABLE.\n\n";
    } else {
        cout << "Status: The selected space is OCCUPIED.\n\n";
    }

    int totalCapacity = 4 * 5;
    cout << "--- Parking Summary ---\n";
    cout << "Total Capacity: " << totalCapacity << " spaces\n";
    cout << "Current Occupancy: " << occupied << " spaces\n";

    return 0;
}
