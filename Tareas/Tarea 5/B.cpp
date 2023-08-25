#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int n; cin >> n;
        int max = 0;
        for (int j = 0; j < n; j++){
            int p; cin >> p;
            max = __gcd(max,abs(p-j-1));
        }
        cout << max << endl;
    }
}