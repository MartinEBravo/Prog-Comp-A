#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    int a,b;
    int A = 0;
    int visited = 0; 
    cin >> n >> m >> k;
    vector <vector <char>> grilla(n, vector<char>(m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char str;
            cin >> str;
            grilla[i][j] = str;
            if (str == '.'){
                A++;
                a = i;
                b = j;
            }
        }
    }
    vector <int> dx = {1, 0, -1, 0};
    vector <int> dy = {0, 1, 0, -1};
    queue <pair<int,int>> q;
    vector <vector <int>> dist(n, vector <int>(m,-1));

    q.push({a,b});
    visited ++;
    dist[a][b] = 0;
    grilla[a][b] = '*';
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        for(int dir=0; dir<4; dir++){
            if (visited >= A - k){
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < m; j++){
                        if (grilla[i][j] == '#'){
                            cout << '#';
                        }
                        else if (grilla[i][j] == '*'){
                            cout << '.';
                        }
                        else{
                            cout << 'X';
                        }
                    }   
                    cout << endl;
                }
                return 0;
            }
            int nx = x+dx[dir];
            int ny = y+dy[dir];
            if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if(grilla[nx][ny] == '#') continue;
            if(dist[nx][ny] != -1) continue;
            grilla[nx][ny] = '*';
            dist[nx][ny] = dist[x][y]+1;
            q.push({nx,ny});
            visited++; // agregar al contador de nodos visitados
        }
        
        
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grilla[i][j] == '#'){
                cout << '#';
            }
            else if (grilla[i][j] == '*'){
                cout << '.';
            }
            else{
                cout << 'X';
            }
        }   
        cout << endl;
    }
}
