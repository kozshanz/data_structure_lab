#include <iostream>

using namespace std;

int main() {
    int matrixA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrixB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    int sumMatrix[3][3];

    cout << "Matrix A:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrixA[i][j] << "   "; 
        }
        cout << "\n";
    }

    cout << "Matrix B:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrixB[i][j] << "   ";
        }
        cout << "\n";
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sumMatrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    cout << "\nSum of Matrix A and B:\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << sumMatrix[i][j] << "  "; 
        }
        cout << "\n";
    }

    return 0;
}
