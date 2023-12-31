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

ll kruskal(int n, vector<tuple<ll,int,int>> &edges, vector <bool> &rel){
	// Algoritmo de Kruskal
	// 
	// Args:
	// 	n: cantidad de nodos
	// 	edges: vector de tuplas donde cada una es una arista {peso, nodo1, nodo2}
	//
	// Retorna:
	// 	El peso de un minimum spanning tree
	// 	Se puede modificar para que entregue las aristas del árbol si es necesario
	//
	// Complejidad: O(m log m) por el sort (m = |edges|)
	
	// Creamos nuestro UnionFind de n nodos (asumimos que están indexados desde 0)

	DSU dsu(n);
	// Ordenamos las aristas por peso de menor a mayor
	sort(edges.begin(), edges.end());

	ll ans = 0; // Acá guardamos la respuesta
	for(auto [w, u, v] : edges){ // (C++17 only)
		// Iteramos por las aristas de menor a mayor peso
		if(dsu.find_set(u) != dsu.find_set(v) && !rel[v]){
			// Si pertenecen a componentes distintas, entonces
			// al unirlas no nos crean un ciclo. Agregamos la arista
			// y unimos las componentes
            rel[v] = true;
			ans += w;
			dsu.union_set(u, v);
		}
	}
    int count = 0;
    for (int i = 0; i < n; i++){
        if (!rel[i]){
            count++;
        }
    }
    if (count != 1) return -1;
    else return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector <bool> rel(n);
    for (int i = 0; i < n; i++){
        int q;
        cin >> q;
    }
    int m;
    cin >> m;
    vector <tuple<ll,int,int>> edges(m); // guardamos aristas como {peso, nodo1, nodo2}
    for (int j = 0; j < m; j++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[j] = {c,a,b};
    }
    cout << kruskal(n, edges, rel);
}
