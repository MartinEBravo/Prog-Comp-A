// Problema E

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


set <ll, ll> chocolates;
set <ll ,ll> frutillas;
int main(){
    int n,m; cin >> n >> m;
    for (int i = 0; i < n; i++){
        ll x,y; cin >> x >> y;
        chocolates.insert({x,y});
    }
    for (int i = 0; i < m; i++){
        ll x,y; cin >> x >> y;
        frutillas.insert({x,y});
    }
    
}