#include <iostream>
using namespace std;

int main() {
    int arr[10];
    cout << "Enter 10 elements: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }
    cout << "\nIndex\tValue" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i << "\t" << arr[i] << endl;
    }
    return 0;
}