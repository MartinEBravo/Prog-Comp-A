#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll INF = 1e18; // debe ser mayor a n*w_maximo = 10^11 (que es el peso del camino más largo posible)

int main(){
    while (true){
        int n, m; 
        cin >> n >> m;
        if (n == 0 && m == 0){
            return 0;
        } 
        int s, d;
        cin >> s >> d;
        // adj[i] = {{u1, w1}, {u2,w2}, ...} ahora se guarda el peso de la arista también (w)
        vector <vector <pair<int,ll>>> adj(n);
        vector <vector <pair<int,ll>>> adj2(n); 
        for(int i=0; i<m; i++){
            int u, v;
            ll w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w}); // arista {u,v} con peso w
            adj2[v].push_back({u, w});
        }

        using state = pair<ll,int>; // esto es para escribir state en vez de pair<ll,int>
        // cola de prioridad que entrega el menor
        priority_queue <state, vector<state>, greater<state>> pq;
        // vector de distancias, inicializamos en INF
        vector <ll> dist(n, INF);

        pq.push({0,s});
        dist[s] = 0;

        while(!pq.empty()){
            auto [peso_camino, u] = pq.top(); // C++17 (structured binding)
            pq.pop();

            if(peso_camino != dist[u]) continue; // ya revisamos un camino mejor hacia u, ignoramos este

            for(auto [v, w] : adj[u]){ // [v,w] de C++17
                // para cada vecino v de u con peso w
                if(peso_camino + w < dist[v]){
                    // encontramos un mejor camino hacia v! actualizamos
                    // su distancia y lo agregamos a la cola
                    dist[v] = peso_camino+w;
                    pq.push({dist[v], v});
                }
            }
        }

        priority_queue <state, vector<state>, greater<state>> pq2;
        // vector de distancias, inicializamos en INF
        vector <ll> dist2(n, INF);

        pq2.push({0,d});
        dist2[d] = 0;

        while(!pq2.empty()){
            auto [peso_camino, u] = pq2.top(); // C++17 (structured binding)
            pq2.pop();

            if(peso_camino != dist2[u]) continue; // ya revisamos un camino mejor hacia u, ignoramos este

            for(auto [v, w] : adj2[u]){ // [v,w] de C++17
                // para cada vecino v de u con peso w
                if(peso_camino + w < dist2[v]){
                    // encontramos un mejor camino hacia v! actualizamos
                    // su distancia y lo agregamos a la cola
                    dist2[v] = peso_camino+w;
                    pq2.push({dist2[v], v});
                }
            }
        }
        vector <vector <pair<int,ll>>> adj3(n); 
        for (int u = 0; u < n; u++){
            for (auto [v, w] : adj[u]){
                if (dist[u] + w + dist2[v] != dist[d]){
                    adj3[u].push_back({v,w});
                }
            }
        }

        priority_queue <state, vector<state>, greater<state>> pq3;
        vector <ll> dist3(n, INF);

        pq3.push({0,s});
        dist3[s] = 0;

        while(!pq3.empty()){
            auto [peso_camino, u] = pq3.top(); // C++17 (structured binding)
            pq3.pop();

            if(peso_camino != dist3[u]) continue; // ya revisamos un camino mejor hacia u, ignoramos este

            for(auto [v, w] : adj3[u]){ // [v,w] de C++17
                // para cada vecino v de u con peso w
                if(peso_camino + w < dist3[v]){
                    // encontramos un mejor camino hacia v! actualizamos
                    // su distancia y lo agregamos a la cola
                    dist3[v] = peso_camino+w;
                    pq3.push({dist3[v], v});
                }
            }
        }
        if (dist3[d] == INF){
            cout << -1 << endl;
        }
        else{
            cout << dist3[d] << endl;
        }
    }
}

