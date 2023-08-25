#include <bits/stdc++.h>
using namespace std;

double dist(long long x, long long y){
    return sqrt(x*x + y*y); // calculamos distancia euclidiana
}

int main(){
    int t; cin >> t;
    for(int j = 0; j < t; j++){
        int n; cin >> n;
        vector <long long> mineros; // Vector de Mineros
        vector <long long> diamantes; // Vector de Diamantes
        for (int i = 0; i < 2*n; i++){
            int x, y; cin >> x >> y;
            if (x == 0){
                mineros.push_back(abs(y)); // Minero
            }
            else{
                diamantes.push_back(abs(x)); // Diamante
            }
        }
        sort(mineros.begin(), mineros.end()); // Se ordenan los mineros
        sort(diamantes.begin(), diamantes.end()); // Se ordenan los diamantes
        double optimo = 0;
        for (int i = 0; i < n; i++){
            optimo += dist(mineros[i], diamantes[i]); // Se obtiene el óptimo
        }
        cout << fixed << setprecision(15) <<  optimo << endl;
    }
}