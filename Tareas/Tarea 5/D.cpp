#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;
ll dividir2 = 5e8 + 4;

int main(){
    ll n; cin >> n;
    ll ans = 0;    
    ll i = 1;
    while (i <= n) {
        ll q = n / i;
        ll r = n / q;
        if (i != r) {
            ll a = ((r % MOD) * ((r + 1) % MOD)) % MOD;
            ll b = (((i - 1) % MOD) * (i % MOD)) % MOD;
            // (a-b)%c = ((((a%c)-(b%c))%c)+c)%c
            ll suma =  ((((a%MOD)-(b%MOD))%MOD)+MOD)%MOD;
            suma = ((suma%MOD)*(dividir2%MOD)) % MOD;
            suma = ((q % MOD) * (suma % MOD)) % MOD;
            ans = ((ans % MOD) + (suma % MOD)) % MOD;
            i = r + 1;
        } else {
            ans = ((ans % MOD) + ((q % MOD) * (i % MOD)) % MOD) % MOD;
            i = r;
        }
    }
    cout << ans;
    return 0;
}
