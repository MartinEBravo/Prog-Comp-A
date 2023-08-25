#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll INF = 1e18; // debe ser mayor a n*w_maximo = 10^11 (que es el peso del camino más largo posible)

int main(){
    int n, m; 
    cin >> n >> m;

    // adj[i] = {{u1, w1}, {u2,w2}, ...} ahora se guarda el peso de la arista también (w)
    vector <vector <pair<int,ll>>> adj(n); 
    for(int i=0; i<m; i++){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; // quizá haya que restarle uno si están indexados de uno
        v--;
        adj[u].push_back({v, w}); // arista {u,v} con peso w
        adj[v].push_back({u, w}); // arista {v,u} con peso w
    }

    using state = pair<ll,int>; // esto es para escribir state en vez de pair<ll,int>
    // cola de prioridad que entrega el menor
    priority_queue <state, vector<state>, greater<state>> pq;
    // vector de distancias, inicializamos en INF
    vector <ll> dist(n, INF);

    vector <int> parent(n, -1);
    vector <bool> vis(n, false);

    pq.push({0,0});
    dist[0] = 0;

    while(!pq.empty()){
        auto [peso_camino, u] = pq.top(); // C++17 (structured binding)
        pq.pop();

        if(vis[u]) continue; // si ya visitamos el nodo, lo ignoramos

        vis[u] = true;

        for(auto [v, w] : adj[u]){ // [v,w] de C++17
            // para cada vecino v de u con peso w
            if(peso_camino + w < dist[v]){
                // encontramos un mejor camino hacia v! actualizamos
                // su distancia, su padre y lo agregamos a la cola
                dist[v] = peso_camino+w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // las distancias finales están en "dist"

    if(!vis[n-1]){
        cout << "-1";
        return 0;
    }

    vector<int> path;
    int u = n-1;
    while(u != -1){
        path.push_back(u);
        u = parent[u];
    }

    for(int i=path.size()-1; i>=0; i--){
        cout << path[i]+1 << " "; 
    }
    cout << "\n";

    return 0;
}
