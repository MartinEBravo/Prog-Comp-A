#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int T; cin >> T;
    while (T--) {
        int j, k, l; cin >> j >> k >> l;
        int impares;
        if (j % 2 == 0 && k % 2 == 0){
            impares = (k-j)/2;
        }
        else if (j % 2 != 0 && k % 2 != 0){
            impares = ((k-j)/2) +1;
        }
        else{
            impares = ((k-j-1)/2)+1;
        }
        if (impares <= l || (k == j && k != 1)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }    
    return 0;
}