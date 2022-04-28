



int main() {
    int n, p;
    
    
    cin >> n;
    
    vector<string> array(n);
    
    int index = 0;
    while(cin >> array[index++] and index < n);
    
    cin >> p;
    
    vector<string> sols(mustMatch);
    
    backtrack(0, mustMatch, 0, array, sols);
    
}
