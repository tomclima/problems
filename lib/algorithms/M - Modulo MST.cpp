/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 10

int pai[MAXN];

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

    sort(edges.begin(), edges.end());
    ll total_cost = 0;
    for(auto [cost, a, b] : edges){
        if(find(a) != find(b)){
            join(a, b);
            total_cost += cost;
        }   
    }

    cout << total_cost % k;


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