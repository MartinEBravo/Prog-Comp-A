#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grafo;
vector<int> visitado;
vector<int> tam;
vector<int> rep;

void bfs(int u, int r) {
    queue<int> q;
    q.push(u);
    visitado[u] = 1;
    rep[u] = r;
    tam[r]++;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < grafo[v].size(); i++) {
            int w = grafo[v][i];
            if (!visitado[w]) {            
                visitado[w] = 1;
                rep[w] = r;
                tam[r]++;
                q.push(w);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    grafo.resize(n + 1);
    visitado.resize(n + 1);
    tam.resize(n + 1, 0);
    rep.resize(n + 1, 0);

    for (int i = 0; i < m; i++){        
        int k;
        cin >> k;
        vector<int> usuarios;
        usuarios.resize(k);
        for (int j = 0; j < k; j++) {
            cin >> usuarios[j];     
        }
        for (int j = 0; j < k - 1; j++) {
            grafo[usuarios[j]].push_back(usuarios[j + 1]);
            grafo[usuarios[j + 1]].push_back(usuarios[j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visitado[i]) {
            bfs(i, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << tam[rep[i]] << " ";
    }

    cout << endl;

    return 0;
}
