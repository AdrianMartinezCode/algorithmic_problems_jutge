

/*

Feu un programa que, donats dos nombres n i x, escrigui tots els multiconjunts que es poden formar amb {1, …, n}, de manera que cada nombre aparegui com a molt x vegades.

Entrada

L’entrada consisteix en un natural n > 0, seguit d’un natural x > 0.

Sortida

Escriviu tots els multiconjunts que es poden formar amb {1, …, n} usant cada nombre com a molt x vegades. Escriviu de petit a gran els nombres dins de cada multiconjunt.

Informació sobre el corrector
Podeu escriure les solucions d’aquest exercici en qualsevol ordre.

Input:
2 3

Output:
{}
{2}
{2,2}
{2,2,2}
{1}
{1,2}
{1,2,2}
{1,2,2,2}
{1,1}
{1,1,2}
{1,1,2,2}
{1,1,2,2,2}
{1,1,1}
{1,1,1,2}
{1,1,1,2,2}
{1,1,1,2,2,2}


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




void backtrack(vector<int>& reps, const int max, const int i) {
    if (i >= reps.size()) {
        printReps(reps);
        return;
    }
    for (int j = 0; j <= max; j++) {
        reps[i] = j;
        backtrack(reps, max, i + 1);
    }
    
}


int main() {
    
    int n, x;
    
    cin >> n;
    cin >> x;

    vector<int> array(n, 0);

    backtrack(array, x, 0);
    
}
