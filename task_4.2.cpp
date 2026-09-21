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
    int evenSum = 0, oddSum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0)
            evenSum += arr[i];
        else
            oddSum += arr[i];
    }
    cout << "\nSum of even elements: " << evenSum << endl;
    cout << "Sum of odd elements:  " << oddSum << endl;
    return 0;
}
