#include <iostream>
#include <vector>
using namespace std;

// generamos la criba de eratostenes
vector<bool> generarPrimos(int n) {
    vector<bool> isPrimo(n + 1, true);
    isPrimo[0] = isPrimo[1] = false;

    for (int i = 2; i * i <= n; ++i) {
        if (isPrimo[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrimo[j] = false;
            }
        }
    }

    return isPrimo;
}

// funcion que calcula la estabilidad, recibe el numero y la criba
int calcularEstabilidad(int num, const vector<bool>& isPrimo) {
    int estabilidad = 1;
    int n = num;
    for (int i = 2; i * i <= num; ++i) {
        // dividimos el numero en sus factores primos
        // luego la cantidad de divisores sera (a+1)(b+1)...
        if (isPrimo[i]) {
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            estabilidad *= (count + 1);
        }
    }
    if (n > 1) {
        estabilidad *= 2;
    }
    return estabilidad;
}

int main() {
    int n;
    cin >> n;
    vector<bool> isPrimo = generarPrimos(1000000);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int estabilidad = calcularEstabilidad(x, isPrimo);
        cout << estabilidad << endl;
    }

    return 0;
}
