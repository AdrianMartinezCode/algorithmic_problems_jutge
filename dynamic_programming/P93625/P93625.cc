
#include <iostream>
#include <vector>
using namespace std;


unsigned int a[31][31];
int solved = 0;


int calc(const int k, const int n) {

    if (solved < n + 1) {

        for (int i = solved; i <= n + 1; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == 0 and j == 0) {
                    a[0][0] = 1;
                } else if (j == 0) {
                    a[i][0] = a[i - 1][0];
                } else if (j == i) {
                    a[i][j] = a[i - 1][j - 1];
                } else {
                    a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                }
            }
        }

        solved = n + 1;
    }

    return a[n][k];
}


int main() {

    int k, n;
    while(cin >> n >> k) cout << calc(k, n) << '\n';
    
}