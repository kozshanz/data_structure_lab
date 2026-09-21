#include <iostream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }
    cout << "Array: ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Even elements: " << evenCount << endl;
    cout << "Odd elements: " << oddCount << endl;
    return 0;
}
