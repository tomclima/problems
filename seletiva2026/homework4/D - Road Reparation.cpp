/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000

int pai[MAXN], tam[MAXN];

int find(int u){
    if (pai[u] == u) return u;
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);
    
    if(u == v) return;
    if(tam[u] < tam[v]) swap(u, v);

    pai[v] = u;
    tam[u]+= tam[v];
}

void init_dsu(){
    for(int u = 0; u < MAXN; u++){
        pai[u] = u;
        tam[u] = 1;
    }
}

int solve(){
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;

    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({c, a -1, b -1});
    }

    sort(edges.begin(), edges.end());

    ll total_cost = 0;
    for(auto [cost, u, v] : edges){
        if(find(u) != find(v)){
            join(u, v);
            total_cost += cost;
        }
    }   

    int possible = true;
    int all_parent = find(0);
    for(int u = 0; u < n and possible; u++){
        if(find(u) != all_parent){
            possible = false;
        }
    }


    if(!possible) cout << "IMPOSSIBLE" << endl;
    else cout << total_cost << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init_dsu();
    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}