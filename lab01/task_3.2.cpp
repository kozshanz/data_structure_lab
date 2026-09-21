#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    int* marks = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " marks: ";
        cin >> marks[i];
    }
    int total = 0, highest = marks[0], lowest = marks[0];
    for (int i = 0; i < n; i++) {
        total += marks[i];
        if (marks[i] > highest) highest = marks[i];
        if (marks[i] < lowest) lowest = marks[i];
    }
    double average = (double)total / n;
    cout << "\nHighest: " << highest << endl;
    cout << "Lowest:  " << lowest << endl;
    cout << "Total:   " << total << endl;
    cout << "Average: " << average << endl;
    delete[] marks;
    return 0;
}
