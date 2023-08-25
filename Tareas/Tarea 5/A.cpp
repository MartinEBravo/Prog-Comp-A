#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> tresDivs(ll n){
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    vector<ll> tresdivs(n + 1, 0);

    for (ll p = 2; p * p <= n; ++p){
        if (is_prime[p]){
            for (ll i = p * p; i <= n; i += p){
                is_prime[i] = false;}}}

    for (ll i = 2; i * i <= n; i++){
        if (is_prime[i]){
            tresdivs[i*i] = 1;}}

    for (ll i = 2; i <= n; i++){
        tresdivs[i] += tresdivs[i-1];}

    return tresdivs;}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    ll MAX = 100000;
    vector<ll> resultado = tresDivs(MAX);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        ll N, K;
        cin >> N >> K;

        if (K > N) K = N;

        ll n_index = sqrt(N);
        ll k_index = sqrt(K);

        int a = 0;
        int b = 0;

        a = resultado[n_index];

        if(K > 1){
            b = resultado[k_index - 1];
        }

        cout << a << " " << a - b << endl;
    }
    return 0;
}
