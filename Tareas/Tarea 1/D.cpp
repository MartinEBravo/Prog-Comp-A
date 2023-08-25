#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    vector<int> vector_a;
    multiset<int> vector_b;
    vector<int> vector_c;
    int n;
    cin >> n;
    vector_a.resize(n);
    vector_c.resize(n);
    for (int i = 0; i < n; i++){
        int num1;
        cin >> num1;
        vector_a[i] = num1;
    }
    for (int i = 0; i < n; i++){
        int num2;
        cin >> num2;
        vector_b.insert(num2);
    }
    for (int i = 0; i < n; i++){
        auto itr = vector_b.lower_bound(n - vector_a[i]);
        if (itr == vector_b.end()){
            itr = vector_b.begin();
        }
        vector_c[i] = (vector_a[i] + *itr) % n;
        vector_b.erase(itr);
    }
    for (int i = 0; i < n; i++){
        cout << vector_c[i] << " ";
    }
}