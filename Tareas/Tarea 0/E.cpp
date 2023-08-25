#include <bits/stdc++.h>

using namespace std;

long long div_ceil(long long x, long long y) {
    return (x + y - 1) / y;
}

bool batalla(long long hc, long long dc, long long hm, long long dm){
    long long turnos_monstruos = div_ceil(hc, dm);
    long long turnos_heroe = div_ceil(hm, dc);
    if(turnos_heroe <= turnos_monstruos){
        return true;
    }
    return false;
}

int main(){
    long long n;
    cin >> n;
    for(long long i = 0; i < n; i++){
        long long hc, dc, hm, dm, k, w, a;
        long long mejorar_hc, mejorar_dc;
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        bool value = false;
        for(mejorar_hc = k; mejorar_hc >= 0; mejorar_hc -= 1){
            mejorar_dc = k - mejorar_hc;
            long long hc_mejorado = hc + mejorar_hc * a;
            long long dc_mejorado = dc + mejorar_dc * w;
            if(batalla(hc_mejorado, dc_mejorado, hm, dm)){
                cout << "YES" << endl;
                value = true;
                break;
            }
        }
        if(!value){
            cout << "NO" << endl;
        }
    }
}