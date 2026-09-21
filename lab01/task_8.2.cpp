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
    cout << "\nBefore: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            arr[i] = 0;
    cout << "\nAfter:  ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
