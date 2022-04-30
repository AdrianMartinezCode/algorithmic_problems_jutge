/*


The Fibonacci numbers Fn are defined as follows:

Fn = 	
⎧
⎪   0	if n = 0 
⎨   1   if n = 1 
⎪   Fn−1 + Fn−2	if n ≥ 2
⎩	

	

Therefore, the first Fibonacci numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, …

For every given natural number n, compute Fn mod108 + 7.

Input

Input consists of several n. Assume 0 ≤ n ≤ 105.

Output

For every given n, print Fn mod108 + 7.

Input:
0
1
10
100000

Output:
0
1
55
33178829

*/
#include <iostream>
#include <vector>
using namespace std;

long long unsigned a[100000], solved = 0;



int fib(const int n) {

    if (n > solved) {
        for (int i = solved; i <= n; i++) {
            if (i == 0) {
                a[0] = 0;
            } else if (i == 1) {
                a[1] = 1;
            } else {
                a[i] = (a[i - 1] + a[i - 2]);
            }
        }
    }
    if (solved < n) solved = n;


    

    return a[n] % (700000000);
}




int main() {

    int n;
    while(cin >> n) cout << fib(n);

}