#include <iostream>
using namespace std;

int main() {
    int marks[8];
    cout << "Enter marks of 8 students:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }
    int total = 0, highest = marks[0], lowest = marks[0];
    for (int i = 0; i < 8; i++) {
        total += marks[i];
        if (marks[i] > highest) highest = marks[i];
        if (marks[i] < lowest) lowest = marks[i];
    }
    double average = (double)total / 8;
    cout << "\nTotal:   " << total << endl;
    cout << "Average: " << average << endl;
    cout << "Highest: " << highest << endl;
    cout << "Lowest:  " << lowest << endl;
    return 0;
}
