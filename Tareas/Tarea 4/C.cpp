#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int N, K; cin >> N >> K;
    if (N == 1 or K == 1){
        cout << "Infinity";
        return 0;
    }
    // Vector con los puntos X,Y
    vector <pair<ll,ll>> puntos(N);
    // Vector con las rectas a,b,c
    // Tal que ax + by + c = 0
    set <tuple<ll,ll,ll>> rectas;
    // Se crean todas los puntos
    for (int i = 0; i < N; i++){
        ll X, Y; cin >> X >> Y;
        puntos[i] = {X,Y};
    }
    // Se crean todos las rectas
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            ll X1, X2, Y1, Y2;
            X1 = puntos[i].first;
            X2 = puntos[j].first;
            Y1 = puntos[i].second;
            Y2 = puntos[j].second;
            ll a,b,c;
            a = Y2 - Y1;
            b = X1 - X2;
            c = -(X1*Y2-X2*Y1);

            // Debemos normalizar estos valores
            // Para no contar varias veces a la misma recta
            ll mcd = gcd(gcd(abs(a), abs(b)), abs(c));
            a /= mcd;
            b /= mcd;
            c /= mcd;

            // Caso de que sean negativos (eliminar los menos)
            if (a < 0 || (a == 0 && b < 0)) {
                a = -a; b = -b; c = -c;
            }

            // Los agregamos al set
            rectas.insert({a,b,c});
        }
    }
    // Probamos que rectas nos sirven
    int Sirve = 0;
    for (auto i = rectas.begin(); i != rectas.end(); i++){
        int count = 0;
        ll a, b, c;
        tie(a,b,c) = *i;
        // Probamos para que puntos pasa la recta
        for (int j = 0; j < N; j++){
            ll X, Y;
            X = puntos[j].first;
            Y = puntos[j].second;
            // Vemos si la recta pasa por el punto
            if (a*X+b*Y+c == 0){
                count++;
            }
        }
        if (count >= K){
            Sirve++;
        }
    }
    cout << Sirve;
    return 0;
}