/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 10

int pai[MAXN];

ll MAX_COST = (ll)10000000000000000;

int find(int u){
    if(pai[u] == u) return u;
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    pai[v] = u;
}

void init_dsu(){
    for(int i = 0; i < MAXN; i++){
        pai[i] = i;
    }
}


int solve(){
    int n, m; cin >> n >> m;
    ll k; cin >> k;

    vector<tuple<ll, int, int>> edges;
    for(int i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        edges.push_back({c, a-1, b-1});
    }

    vector<bool> used_edges(m, 0);
    for(int i = 0; i < n-1; i++){
        used_edges[i] = 1;
    }
    reverse(used_edges.begin(), used_edges.end());
    
    ll best = MAX_COST;
    do{
        // perform dsu
        ll cumulative = 0;
        init_dsu();
        for(int i = 0; i < n; i++){
            if(used_edges[i]){
                auto [cost, a, b] = edges[i];
                cumulative += cost;
                join(a, b);
            }
        }

        // check if is spanning tree
        bool is_tree = 1;
        for(int i = 0; i < n-1 and is_tree; i++){
            if(pai[i] != pai[i+1]) is_tree = false; 
        }

        if(is_tree){
            best = min(best, cumulative % k);
        }
    }while(next_permutation(used_edges.begin(), used_edges.end()));


    cout << best << endl;

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