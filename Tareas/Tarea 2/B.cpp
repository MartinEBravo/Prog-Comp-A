#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grafo;
vector<int> dist;
vector<int> parent;

void bfs(int s, int n){
    dist.assign(n, -1);
    parent.assign(n, -1);

    queue <int> cola;
    dist[s] = 0;
    cola.push(s);
    while(!cola.empty()){
        int u = cola.front(); cola.pop();

        for(int v: grafo[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                cola.push(v);
            }
        }
    }
    if (dist[n-1] != -1){
        cout << dist[n-1] + 1<< endl;
        vector<int> path;
        for(int i = n-1; i != -1; i = parent[i]){
            path.push_back(i);       
        }
        reverse(path.begin(), path.end());
        for(int p : path){
            cout << p+1 << " ";
        }
        cout << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    grafo.assign(n, vector<int>());
    while (m--){
        int num1, num2;
        cin >> num1 >> num2;
        grafo[num1-1].push_back(num2-1);     
        grafo[num2-1].push_back(num1-1);
    }    
    bfs(0, n);   
}

