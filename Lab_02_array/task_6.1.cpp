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
    int pos;
    cout << "Enter position to delete (0-based): ";
    cin >> pos;
    cout << "\nBefore deletion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
    cout << "\nAfter deletion:  ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
