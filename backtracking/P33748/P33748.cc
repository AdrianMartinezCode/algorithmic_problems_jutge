#include <iostream>
#include <vector>
using namespace std;


/*
 * 

 https://jutge.org/problems/P33748
 

Feu un programa que, donats un nombre m i n paraules diferents s1, …, sn, escrigui tots els subconjunts de m elements que es poden formar amb les paraules.

Entrada

L’entrada consisteix en dos naturals m i n, seguits de s1, …, sn. Assumiu n > 0 i 0 ≤ m ≤ n.

Sortida

Escriviu tots els subconjunts de m paraules que es poden formar amb s1, …, sn.
Informació sobre el corrector

Podeu escriure en qualsevol ordre tant les solucions com els elements dins de cada solució. 

 */

void backtrack(int i, int mustMatch, int matches, const vector<string>& array, vector<string>& sols) {
    
    
    if (matches == mustMatch) {
        
        bool first = true;
        int printed = 0;
        cout << '{';
        while(printed < mustMatch) {
            
            if (first) {
                first = false;
            } else {
                cout << ',';
            }
            cout << sols[printed];
            printed++;
        }
        cout << "}\n";
        
        
    } else if (i < array.size()) {
        
        sols[matches] = array[i];
        backtrack(i + 1, mustMatch, matches + 1, array, sols);
        
        backtrack(i + 1, mustMatch, matches, array, sols);
        
    }
}




int main() {
    int nWords, mustMatch;
    
    cin >> mustMatch;
    cin >> nWords;
    
    vector<string> array(nWords);
    
    int index = 0;
    while(cin >> array[index++] and index < nWords);
    
    vector<string> sols(mustMatch);
    
    backtrack(0, mustMatch, 0, array, sols);
    
}
