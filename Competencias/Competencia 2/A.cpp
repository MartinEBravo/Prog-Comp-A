#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// a = 12   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
// gcd(a,b) | 1 | 2 | 3 | 4 | 1 | 6 | 1 | 4 | 3 | 2  | 1  | 12 | = 6

int main(){
    ll contador = 1;    
    ll b; cin >> b;
    for(ll i=2; i*i<=b; i++){
        if(b%i==0)contador++;
    }
    ll div = 2*contador;
    ll sqrt_ = (ll) sqrt(b);
    if(sqrt_*sqrt_ == b) div--;
    cout << div << endl;
}
