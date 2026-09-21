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
    int choice, val;
    cout << "\nInsert at: 1) Beginning  2) Middle  3) End" << endl;
    cout << "Choice: ";
    cin >> choice;
    cout << "Enter value to insert: ";
    cin >> val;
    int pos;
    if (choice == 1)
        pos = 0;
    else if (choice == 2)
        pos = n / 2;
    else
        pos = n;
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
