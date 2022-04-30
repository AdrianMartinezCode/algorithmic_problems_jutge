

/*

https://jutge.org/problems/P70914_ca

Feu un programa que, donats tres nombres n, x i y, escrigui tots els multiconjunts que es poden formar amb {1, …, n}, de manera que cada nombre aparegui entre x i y vegades.

Entrada

L’entrada consisteix en un natural n > 0, seguit d’un natural x ≥ 0, seguit d’un natural y > x.

Sortida

Escriviu tots els multiconjunts que es poden formar amb {1, …, n} usant cada nombre entre x i y vegades. Escriviu de petit a gran els nombres dins de cada multiconjunt.

Informació sobre el corrector
Podeu escriure les solucions d’aquest exercici en qualsevol ordre.

Input:
2 1 4

Output:
{1,2}
{1,2,2}
{1,2,2,2}
{1,2,2,2,2}
{1,1,2}
{1,1,2,2}
{1,1,2,2,2}
{1,1,2,2,2,2}
{1,1,1,2}
{1,1,1,2,2}
{1,1,1,2,2,2}
{1,1,1,2,2,2,2}
{1,1,1,1,2}
{1,1,1,1,2,2}
{1,1,1,1,2,2,2}
{1,1,1,1,2,2,2,2}



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




void backtrack(vector<int>& reps, const int min, const int max, const int i) {
    if (i >= reps.size()) {
        printReps(reps);
        return;
    }
    for (int j = min; j <= max; j++) {
        reps[i] = j;
        backtrack(reps, min, max, i + 1);
    }
    
}


int main() {
    
    int n, x, y;
    
    cin >> n;
    cin >> x;
    cin >> y;

    vector<int> array(n, 0);

    backtrack(array, x, y, 0);
    
    
}
