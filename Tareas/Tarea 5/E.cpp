#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll G(int n){
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += __gcd(i,n);
    }
    return ans;
}

ll T(int n){
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += G(i);
    }
    return ans;
}

int main(){
    while (true){
        int n; cin >> n;
        if (!n) return 0;
        else{
            cout << T(n) << endl;
        }
    }

    return 0;
}