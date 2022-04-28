


void backtrack(vector<int>& reps) {
    
    bool first = false;
    for (int i = 0; i < reps; i++) {
        for (int j = 0; j < reps[i]; j++) {
            if (first) {
                first = true;
            } else {
                cout << ',';
            }
            cout << i;
        }
    }
    
    backtrack()
    
}


int main() {
    
    int n, x;
    
    cin >> n;
    cin >> x;
    
    
}
