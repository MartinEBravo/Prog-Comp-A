#include <bits/stdc++.h>
using namespace std;
bool esbella(string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    while (n--) { 
        int num1, num2;
        string str1, str2;
        cin >> num1 >> num2 >> str1 >> str2;
        string torre_repetida, torre_bella;
        if (esbella(str1)) {
            torre_bella = str1;
            torre_repetida = str2;
        }
        else {
            torre_bella = str2;
            torre_repetida = str1;
        }
        bool resultado;
        bool cumplido = false;
        if (esbella(torre_repetida) && esbella(torre_bella)) {
            cumplido = true;
        }
        else {
            while (true) {
                char ultimo = torre_repetida.back();
                torre_bella.push_back(ultimo);
                torre_repetida.pop_back();
                resultado = esbella(torre_repetida) && esbella(torre_bella);
                if (resultado) {
                    cumplido = true;
                    break;
                }
                if (torre_repetida.empty()) {
                    break;
                }
            }
        }
        cout << (cumplido ? "YES" : "NO") << endl;
    }
}
