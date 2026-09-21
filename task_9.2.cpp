#include <iostream>
using namespace std;

int main() {
    int matrix[3][3];
    cout << "Enter elements of 3x3 matrix:" << endl;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 3; j++)
            rowSum += matrix[i][j];
        cout << "Row " << i + 1 << " Sum = " << rowSum << endl;
    }
    cout << endl;
    for (int j = 0; j < 3; j++) {
        int colSum = 0;
        for (int i = 0; i < 3; i++)
            colSum += matrix[i][j];
        cout << "Column " << j + 1 << " Sum = " << colSum << endl;
    }
    return 0;
}
