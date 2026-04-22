/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<int, int >
vector<int> dx = {-1, 0, +1, 0};
vector<int> dy = {0, -1, 0, +1};


bool check_valid(int y, int x, vector<string> &graph){
    if(y < 0 or y >= graph.size()) return false;
    if(x < 0 or x >= graph.size()) return false;
    if(graph[y][x] == '#') return false;
    return true;
}


int solve(){
    int n, q; cin >> n >> q;
    vector<int> crumbs(n*n);
    
    int total_empty = 0;
    vector<pii> exits;
    
    vector<string> grid(n);
    for(int i = 0; i < n; i++){
        cin >> grid[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '.') total_empty++;    
            else if(grid[i][j] == 'E') exits.push_back({i, j});
        }
    }
    
    vector<vector<int>> dist(n, vector<int> (n, -1));
    queue<pii> fila;
    for(auto e: exits){
        dist[e.first][e.second] = 1;
        fila.push(e);      
    }
    
    while(!fila.empty()){
        
        auto v = fila.front();
        fila.pop();
        
        for(int i = 0; i < 4; i++){
            int y = v.first + dy[i];
            int x = v.second + dx[i];
            if(check_valid(y, x, grid) and dist[y][x] == -1){
                dist[y][x] = dist[v.first][v.second] +1;
                crumbs[dist[y][x]]++;
                fila.push({y, x});
            }
        }
    }
    
    vector<int> prefix(n*n+1);
    for(int i = 1; i <= n*n; i++){
        prefix[i] = crumbs[i] + prefix[i-1];
    }

    for(int i = 0; i < q; i++){
        int query; cin >> query;
        cout << setprecision(12) << fixed << (long double)prefix[query]/(long double)total_empty << endl;
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