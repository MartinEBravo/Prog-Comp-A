#include <bits/stdc++.h>
using namespace std;

int t;
int times = 0;
vector <pair<int,int>> positions;
vector <int> visited;

void dfs(int s){
    stack <int> Pila;
    Pila.push(s);

    while (!Pila.empty()){
        int u = Pila.top(); 
        Pila.pop();
        visited[u] = 1;
        for (int i = 0; i < t; i++){
            if (visited[i] == 0){
                if (positions[u].first == positions[i].first or positions[u].second == positions[i].second ){
                    visited[i] = 1;
                    Pila.push(i);
                }
            }
        }
    }
    times ++;
}

int main(){
    cin >> t;
    positions.resize(t);
    visited.resize(t);
    for (int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;
        positions[i] = make_pair(x,y);
    }
    for (int i = 0; i < t; i++){
        if (visited[i] == 0)
            dfs(i);
    }
    cout << times - 1;
}


