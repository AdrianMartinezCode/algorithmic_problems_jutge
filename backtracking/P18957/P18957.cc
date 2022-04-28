#include <iostream>
#include <vector>
using namespace std;

/*

https://jutge.org/problems/P18957_ca
 
Feu un programa que, donades n paraules diferents s1, …, sn, escrigui tots els subconjunts que es poden formar amb les paraules.

Entrada

L’entrada consisteix en un nombre n > 0, seguit de s1, …, sn.

Sortida

Escriviu tots els subconjunts que es poden formar amb s1, …, sn.
Informació sobre el corrector

Podeu escriure en qualsevol ordre tant les solucions com els elements dins de cada solució. 
*/



void backtrack(int i, const vector<string>& array, vector<bool>& pos) {
    if (i < array.size()) {
        pos[i] = true;
        backtrack(i + 1, array, pos);
        pos[i] = false;
        backtrack(i + 1, array, pos);
    } else {
        cout << '{';
        bool first = true;
        for (int j = 0; j < pos.size(); j++) {
            if (pos[j]) {
                if (first) {
                    first = false;
                } else {
                    cout << ',';
                }
                cout << array[j];
            }
        }
        cout << "}\n";
    }
}




int main() {
    int nWords;
    
    cin >> nWords;
    
    vector<string> array(nWords);
    
    int index = 0;
    while(cin >> array[index++]);
    
    vector<bool> pos(nWords, false);
    
    backtrack(0, array, pos);
    
    
    
}
