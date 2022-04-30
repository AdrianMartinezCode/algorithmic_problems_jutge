/*

https://jutge.org/problems/P22110_ca

Feu un programa que, donats dos nombres n i t, 
escrigui tots els multiconjunts de t nombres que es 
poden formar amb {1, …, n}.

Entrada

L’entrada consisteix en un natural n > 0, 
seguit d’un natural t ≥ 0.

Sortida

Escriviu tots els multiconjunts de mida t que es 
poden formar amb {1, …, n}. Escriviu de petit a gran 
els nombres dins de cada multiconjunt.

Informació sobre el corrector
Podeu escriure les solucions d’aquest exercici en qualsevol ordre.


Input:
3 3


Output:
{3,3,3}
{2,3,3}
{2,2,3}
{2,2,2}
{1,3,3}
{1,2,3}
{1,2,2}
{1,1,3}
{1,1,2}
{1,1,1}

*/

#include <iostream>
#include <vector>
using namespace std;


void printReps(vector<int>& reps) {
    cout << '{';
    bool first = true;
    for (int i = 0; i < reps.size(); i++) {
        
        for (int j = 0; j < reps[i]; j++) {
            if (first) {
                first = false;
            } else {
                cout << ',';
            }
            cout << (i + 1);
        }
    }
    cout << '}';
    cout << '\n';
}

// int sum(vector<int>& v) {
//     int s = 0;
//     for (int i = 0; i <  v.size(); i++) {
//         s += v[i];
//     }
//     return s;
// }


void backtrack(vector<int>& reps, const int max, const int total, const int sum, const int i) {
    
    if (i >= reps.size()) {
        if (sum == total) {
            printReps(reps);
        }
        return;
    }
    for (int j = 0; j <= max; j++) {
        reps[i] = j;
        // if (sum + j >= total) return;
        backtrack(reps, max, total, sum + j, i + 1);
    }
    
}





int main() {
    
    int n, x;
    
    cin >> n;
    cin >> x;

    vector<int> array(n, 0);

    backtrack(array, n, x, 0, 0);
    
}
