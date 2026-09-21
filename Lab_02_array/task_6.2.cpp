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
    cout << "Enter value to search and delete: ";
    cin >> key;
    cout << "\nBefore deletion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            for (int j = i; j < n - 1; j++)
                arr[j] = arr[j + 1];
            n--;
            found = true;
            break;
        }
    }
    if (found) {
        cout << "\nAfter deletion:  ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    } else {
        cout << "\nElement not found." << endl;
    }
    return 0;
}
