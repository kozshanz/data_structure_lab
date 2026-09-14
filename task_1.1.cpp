#include <iostream>
using namespace std;
int main()
{
    int arr[10];
    cout << "Enter 10 elements:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    cout << "\nArray Traversal:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}