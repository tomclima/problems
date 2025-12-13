/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define UNALLOWED 'U'
#define pii pair<int, int>

vector<pii> dxy = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool pii_legal(pii pair, int n, int m){
    int legal = true;
    if(pair.first >= n or pair.second >= m) legal = false;
    if(pair.first < 0 or pair.second < 0) legal = false;
    return legal;
}

pii pii_add(pii p1, pii p2){
    return {p1.first + p2.first, p1.second + p2.second};
}

int solve(){
    int n, m; cin >> n >> m;
    vector<string> map(n);
    
    vector<char> guards{'>', '<', '^', 'v'};
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }
    
    // check guard vision
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(map[i][j] == '>'){
                int k = j+1;
                while(k < m and find(guards.begin(), guards.end(), map[i][k]) == guards.end()){
                    map[i][k] = UNALLOWED;
                    k++;
                }
            }
            
            else if(map[i][j] == '<'){
                int k = j-1;
                while(k >= 0 and find(guards.begin(), guards.end(), map[i][k]) == guards.end()){
                    map[i][k] = UNALLOWED;
                    k--;
                }
            }
            
            else if(map[i][j] == '^'){
                int k = i-1;
                while(k >= 0 and find(guards.begin(), guards.end(), map[k][j]) == guards.end()){
                    map[k][j] = UNALLOWED;
                    k--;
                }
            }
            
            else if(map[i][j] == 'v'){
                int k = i+1;
                while(k < n and find(guards.begin(), guards.end(), map[k][j]) == guards.end()){
                    map[k][j] = UNALLOWED;
                    k++;
                }
            }
            
        }
    }
    
    // BFS GRID
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    vector<vector<pii>> parent(n, vector<pii>(m, {-1, -1}));
    queue<pii> queue;
    visited[0][0] = true;
    queue.push({0, 0});
    while(!queue.empty()){
        
        pii u = queue.front(); queue.pop();
        for(auto i : dxy){
            auto v = pii_add(u, i);
            
            if(pii_legal(v, n, m) and map[v.first][v.second] != UNALLOWED and find(guards.begin(), guards.end(), map[v.first][v.second]) == guards.end()){
                if(!visited[v.first][v.second]){
                    visited[v.first][v.second] = true;
                    queue.push({v.first, v.second});
                    parent[v.first][v.second] = {u.first, u.second};

                }
            }
        }
    }

    if(parent[n-1][m-1].first == -1 or map[0][0] == UNALLOWED) {
        cout << -1;
        return 0;
    }

    pii v = {n-1, m-1};
    while(parent[v.first][v.second].first != -1){
        map[v.first][v.second] = 'X';
        v = parent[v.first][v.second];
    }
    map[0][0] = 'X';

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == UNALLOWED){
                map[i][j] = '.';
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << map[i] << endl;
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