#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int T; cin >> T;
    while (T--){
        ll K,P,N; cin >> K >> P >> N;
        P = min(K,P);
        cout << (K-P)*N << endl;
    }
    return 0;
}