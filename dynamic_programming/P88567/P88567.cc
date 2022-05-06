/*

Given a grid with uppercase letters, compute the sum of the values of the letters in each rectangle with a corner in the upper-left extreme. The values of the letters are ’A’=1, ’B’=1+2=3, ’C’=1+2+3=6, ’D’=1+2+3+4=10, etcetera, up to ’Z’=351.

Input

Input consists of 0< r≤ 500 lines, all of them with the same number of uppercase letters 0<c≤ 500.

Output

Print r lines with c numbers each. The j-th number of the i-th row must be the sum of the values of the letters of the rectangle whose corners are the first letter of the input, and the j-th letter of the i-th row.

Hint

Consider using the inclusion-exclusion principle.



Input

ZA
AZ

Output

351 352
352 704



Input

ABCD
EFGH
IJKL

Output

1 4 10 20
16 40 74 120
61 140 240 364
*/
#include <iostream>
#include <vector>
using namespace std;

const int letters = 'Z' - 'A' + 1;

int sumsLetters[letters];
int lastComputedIndex = 0;

int convertCharToIndex(char c) {
    return (int)c - 'A';
}


int computeLetter(char c) {
    int index = convertCharToIndex(c);
    if (lastComputedIndex >= index) return sumsLetters[index];
    for (int i = lastComputedIndex; i <= index; i++) sumsLetters[i] = sumsLetters[i - 1] + (i + 1);
    lastComputedIndex = index;
    return sumsLetters[index];
}


void computeLines(const vector<string>& lines) {
    int n = lines.size();
    int m = lines[0].size();
    int a[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0 and i == 0) {
                a[0][0] = computeLetter(lines[0][0]);
            } else if (j == 0) {
                a[i][0] = a[i - 1][0] + computeLetter(lines[i][0]);
            } else if (i == 0) {
                a[0][j] = a[0][j - 1] + computeLetter(lines[0][j]);
            } else {
                a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + computeLetter(lines[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        bool firstInner = true;
        for (int j = 0; j < m; j++) {
            if (firstInner) firstInner = false;
            else cout << ' ';
            cout << a[i][j];
        }
        cout << '\n';
    }
}

int main() {

    sumsLetters[0] = 1;

    vector<string> lines;
    string line;
    while(cin >> line) {
        lines.push_back(line);
    }

    computeLines(lines);


}