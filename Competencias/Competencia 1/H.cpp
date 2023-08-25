#include <bits/stdc++.h>
using namespace std;

int INF = 1e6;

int div_ceil(int x, int y){
    if (y == 0){
        return INF;
    }
    return (x+y-1)/y;
}

int abs(int x){
    if (x >= 0){
        return x;
    }

    return -x;
}

// Función Batalla, retorna quien gana dadas las habilidades mejoradas
bool ganaSapo(int new_HPsa, int new_ATKsa, int new_DEFsa, int HPese, int ATKese, int DEFese){

    int Sapo, EvilSepo;

    if (new_ATKsa <= DEFese){
        EvilSepo = INF;
    } else {
        EvilSepo = div_ceil(HPese, new_ATKsa - DEFese);
    }

    if (ATKese <= new_DEFsa){
        Sapo = INF;
    } else {
        Sapo = div_ceil(new_HPsa , ATKese - new_DEFsa);
    }

    if (EvilSepo < Sapo){
        return true;
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int minimo = INF;

    // Salud, Ataque y Defensa de Sapo
    int HPsa, ATKsa, DEFsa;
    cin >> HPsa >> ATKsa >> DEFsa;

    // Salud, Ataque y Defensa de Evil Sepo
    int HPese, ATKese, DEFese;
    cin >> HPese >> ATKese >> DEFese;

    // Precio de Salud, Ataque y Defensa Extra
    int h, a, d;
    cin >> h >> a >> d;

    // Se harán todas las posibilidades de moscas hasta que se encuentre
    // i son la cantidad de moscas por gastar
    for (int i = 0; i <= 1000; i++){

        // Se elige un número entre 0 e i para comprar vida
        for (int j = 0; j <= i; j++){

            // Compramos k*a ataque
            int new_ATKsa = ATKsa;
            new_ATKsa += j/a;

            // Nos quedan i-j moscas para comprar, 
            // Eligiremos un número para comprar ataque entre 0 e i-j
            for (int k = 0; k <= i - j; k++){

                // Luego nos queda i-j-k para comprar defensa
                int new_DEFsa = DEFsa;
                new_DEFsa += k/d;

                // Compramos j*h vida
                int new_HPsa = HPsa;
                new_HPsa += (i-j-k)/h;

                // Comprobamos si Sapo puede ganar
                if (ganaSapo(new_HPsa, new_ATKsa, new_DEFsa, HPese, ATKese, DEFese)){
                    minimo = min(minimo,i);
                }
            }
        }
        if (minimo!=INF){break;}
    }

    cout << minimo;
}
