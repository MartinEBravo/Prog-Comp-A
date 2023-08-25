// Problema B
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set <tuple<ll, ll, ll>> calles;

int main(){
    ll x1, y1; // punto inicial
    ll x2, y2; // punto final
    cin >> x1 >> y1 >> x2 >> y2;
    int n; // cantidad de calles
    cin >> n;
    for (int i = 0; i < n; i++){
        ll a, b, c; // ecuacion calle
        cin >> a >> b >> c;
        calles.insert({a,b,c});
    }
    int count = 0;
    // Para cada calle analizamos si sirve la recta o no
    for (auto i = calles.begin(); i != calles.end(); i++){
        ll a,b,c;
        tie(a,b,c) = *i;
        if (b!=0){
            ll Y1b = -(a*x1 + c);
            ll Y2b = -(a*x2 + c);
            if ((y1*b - Y1b > 0 && y2*b - Y2b < 0) || (y1*b - Y1b < 0 && y2*b - Y2b > 0)){
                count++;
            }
        }
        else{
            if ((x1*a > -c && x2*a < -c) || (x1*a < -c && x2*a > -c)){
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
