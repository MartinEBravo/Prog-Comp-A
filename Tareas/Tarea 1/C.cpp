#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    long long times = 0;
    map <int, int> mapa_x;
    map <int, int> mapa_y;
    map <pair<int, int>, int> mapa_xy;

    for (int i = 0; i < n; i++){
        int num1, num2;
        cin >> num1 >> num2;
        times += mapa_x[num1] + mapa_y[num2] - mapa_xy[{num1, num2}];
        mapa_x[num1]++;
        mapa_y[num2]++;
        mapa_xy[{num1, num2}]++;
    }
    cout << times << endl;
    return 0;
}