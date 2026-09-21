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
    int sum = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            sum += matrix[i][j];
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    cout << "Sum of all elements: " << sum << endl;
    return 0;
}
