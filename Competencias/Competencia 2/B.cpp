#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


// Necesitamos UnionFind para Kruskal
struct DSU{ //Disjoint Set Union (o Union Find)
    // Casi O(1) amortizado
    vector <int> parent, sz; // sz = size
    DSU(int n){
        parent.resize(n);
        sz.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find_set(int v){
        if(v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(sz[a] < sz[b])
                swap(a,b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};

int main(){
    int n, m; cin >> n >> m; 
    ll mayor_ = 1;
    ll comp_conexas = n;
    vector<ll> numero_comp_conexas(n,1);
    // n son la cantidad de ciudades
    // m la cantidad de días/caminos
    DSU dsu(n);
    for (int i = 0; i < m; i++){
        // camino (a,b) es agregado
        ll a,b; cin >> a >> b; a--;b--;
        if(dsu.find_set(a)!=dsu.find_set(b)){
            ll c1,c2;
            c1 = numero_comp_conexas[dsu.find_set(a)];
            c2 = numero_comp_conexas[dsu.find_set(b)];
            dsu.union_set(a,b);

            numero_comp_conexas[dsu.find_set(a)] = c1 + c2;
            comp_conexas--;
            mayor_ = max(mayor_, numero_comp_conexas[dsu.find_set(a)]);
        }
        cout<<comp_conexas<<" "<<mayor_<<endl;
    }
    
}