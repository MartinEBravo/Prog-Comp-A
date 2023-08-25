#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 1e18; // Peso arbitrario mayor al mayor peso posible

int main(){
    int n, m; // nodos y aristas
    cin >> n >> m;
    // se guarda el peso de la arista
    // adj[i] = {{u1,w1},{u2,w2},...}
    vector <vector <pair<int,ll>>> adj(n+n);
    for (int i = 0; i < m; i++){
        int a, b; // nodos a,b
        ll c; // peso c
        cin >> a >> b >> c;
        a--; // restamos uno si están indexados de uno
        b--;
        adj[a].push_back({b,c}); // arista {a,b} con peso c
        adj[a+n].push_back({b+n,c});
        adj[a].push_back({b+n, floor(c/2)});
    }
    // cola de prioridad que entrega el menor
    priority_queue <pair<ll,int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    // vector de distancias, inicializamos en INF
    vector <ll> dist(2*n, INF);

    pq.push({0,0});
    dist[0] = 0;

    while(!pq.empty()){
        auto [peso_camino, a] = pq.top();
        pq.pop();

        if(peso_camino != dist[a]) continue;

        for(auto [b,c] : adj[a]){
            if (peso_camino + c < dist[b]){
                dist[b] = peso_camino + c;
                pq.push({dist[b], b});

            }
        }
    }
    cout << dist[2*n-1];
    return 0;
}
