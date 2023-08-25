#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int nfactorizable(int x, const vector<bool>& isPrimo, vector<int>& criba) {
    if (x == 1)
        return 0;
    
    if (criba[x] != -1)
        return criba[x];

    int count = 0;
    for (int i = 2; i * i <= x; ++i) {
        // dividimos el numero en sus factores primos
        // luego la cantidad de divisores sera (a+1)(b+1)...
        if (isPrimo[i]) {
            if (x % i == 0) {
                while (x % i == 0) {
                    x /= i;
                }
                count++;
            }
        }
    }
    if (x > 1) {
        count++;
    }

    criba[x] = count;
    return count;
}

int main() {
    int T;
    cin >> T;
    vector<bool> isPrimo = generarPrimos(1000000);
    while (T--) {
        int a, b, n;
        cin >> a >> b >> n;
        vector<int> criba(b + 1, -1);
        int count = 0;
        for (int i = a; i <= b; i++) {
            if (nfactorizable(i, isPrimo, criba) == n) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
