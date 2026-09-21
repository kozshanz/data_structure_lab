#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Array in reverse order: ";
    for (int i = 9; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
