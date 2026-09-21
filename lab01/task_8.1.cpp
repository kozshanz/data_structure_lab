#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }
    cout << "\nArray: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    int index, newVal;
    cout << "\nEnter index to update: ";
    cin >> index;
    cout << "Enter new value: ";
    cin >> newVal;
    arr[index] = newVal;
    cout << "Updated array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
