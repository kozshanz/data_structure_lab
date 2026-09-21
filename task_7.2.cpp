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
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    cout << "Found at indexes: ";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found)
        cout << "Element Not Found.";
    cout << endl;
    return 0;
}
