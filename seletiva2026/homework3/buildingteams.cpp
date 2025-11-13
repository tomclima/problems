/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

bool percorrer_grafo(vector<vector<int>> &graph, stack<int> &fila, vector<int> &cor, vector<bool> &visited){
    while(!fila.empty()){
            int u = fila.top();
            fila.pop();
            for(auto v : graph[u]){
                if(cor[v] == cor[u]){
                    return false;
                }

                if(!visited[v]){
                    cor[v] = !cor[u];
                    visited[v] = true;
                    fila.push(v);
                }
            }
        }
    return true;
}

int solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    stack<int> fila;
    vector<int> cor(n, -1);
    vector<bool> visited(n);
    bool possible = true;
    for(int i = 0; i < n and possible; i++){
        if(!visited[i]){
            fila.push(i);
            visited[i] = true;
            cor[i] = 1;
            possible &= percorrer_grafo(graph, fila, cor, visited);
        }
    }
    

    if(!possible) cout << "IMPOSSIBLE";
    else{
        for(int i = 0; i < n; i++){
            cout << cor[i]+1 << " ";
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}