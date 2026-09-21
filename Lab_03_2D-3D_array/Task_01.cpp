#include <iostream>
#include <string>

using namespace std;

int main() {
int marks[6][4] = {
{85, 90, 88, 92},
{78, 85, 80, 88},
{92, 95, 98, 90},
{65, 70, 75, 80},
{88, 82, 85, 89},
{75, 78, 82, 85}
};

string subjects[4] = {"English", "Maths", "Prog", "AI"};

cout << "--- Complete Marks Table ---\n";
cout << "Student\tEng\tMath\tProg\tAI\n";
for (int i = 0; i < 6; i++) {
cout << i + 1 << "\t";
for (int j = 0; j < 4; j++) {
cout << marks[i][j] << "\t";
}
cout << "\n";
}
cout << "\n";

int highestTotal = 0;
int bestStudent = 0;

cout << "--- Total and Average ---\n";
for (int i = 0; i < 6; i++) {
int total = 0;
for (int j = 0; j < 4; j++) {
total += marks[i][j];
}

float average = total / 4.0;
cout << "Student " << i + 1 << " -> Total: " << total << ", Average: " << average << "\n";

if (total > highestTotal) {
highestTotal = total;
bestStudent = i;
}
}
cout << "\n";

cout << "--- Highest in Each Subject ---\n";
for (int j = 0; j < 4; j++) {
int maxMark = marks[0][j];
for (int i = 1; i < 6; i++) {
if (marks[i][j] > maxMark) {
maxMark = marks[i][j];
}
}
cout << subjects[j] << ": " << maxMark << "\n";
}
cout << "\n";

cout << "--- Top Student ---\n";
cout << "Student " << bestStudent + 1 << " got the highest total marks: " << highestTotal << "\n";

return 0;
}
