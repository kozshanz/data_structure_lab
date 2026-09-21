#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[101];
    for (int i = 0; i < n; i++) {
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }
    int pos, val;
    cout << "Enter position to insert (0-based): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;
    cout << "\nBefore insertion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
    cout << "\nAfter insertion:  ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
