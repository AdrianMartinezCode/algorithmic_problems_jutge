
#include <iostream>
#include <vector>
using namespace std;


int a[100000][100000];


int main() {


    int curr = 0;
    int n;

    while(cin >> n) {
        int t[n], i = 0;

        while(cin >> t[i++] and i < n);

        // for (int j = 0; j < n; j++) {
        //     cout << a[j] << " ";
        // }

        int q;

        cin >> q;

        cout << '#' << (curr + 1) << '\n';
        int p, c;
        i = 0;
        while(i < q) {
            cin >> p >> c;
            int sum = 0;

            if (p > c) {
                for (int j = p - 1; j >= c - 1; j--) {
                    sum += t[j];
                }
            } else {
                for (int j = p - 1; j < c; j++) {
                    sum += t[j];
                }
            }

            
            cout << sum << '\n';
            i++;
        }


        curr++;
    }

    

    
    


}