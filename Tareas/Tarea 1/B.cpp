#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int num;
    cin >> num;
    vector<int> L(num);
    for (int i = 0; i < num; i++){
        cin >> L[i];
    }
    
    set<int> elements;
    int max_len = 0;
    int j = 0;
    for (int i = 0; i < num; i++) {
        while (j < num && elements.find(L[j]) == elements.end()) {
            elements.insert(L[j]);
            j++;
        }
        max_len = max(max_len, j-i);
        elements.erase(L[i]);
    }
    cout << max_len;
}


