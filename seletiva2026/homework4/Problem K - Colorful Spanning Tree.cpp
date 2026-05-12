/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pll pair<ll, ll>

vector<int> pai(1000+1000000);

using Edge = tuple<ll, int, int>;

int find(int u){
    if(pai[u] == u) return pai[u];
    else return pai[u] = find(pai[u]);
}

int join(int u, int v){
    u = find(u);
    v = find(v);
    return pai[u] = v;
}

int init_dsu(){
    for(int i = 0; i < pai.size(); i++){
        pai[i] = i;
    }
    return 0;
}

int solve(){
    
    int n; cin >> n;
    vector<int> colors(n);

    ll total_vertices = n;
    for(int i = 0; i < n; i++){
        cin >> colors[i];
        total_vertices += colors[i];
    }

    
    vector<priority_queue<ll, vector<ll>, greater<ll>>> graph(n);
    priority_queue<Edge, vector<Edge>, greater<Edge>> edges;
     
    for(int i = 0; i <n; i++){
        for(int j = 0; j < n; j++){
            ll cost; cin >> cost;
            edges.push({cost, i, j});
            graph[i].push(cost);
        }
    }


    ll total_cost = 0;
    while(!edges.empty()){
        auto [cost, u, v] = edges.top();
        edges.pop();
        if(find(u) != find(v)){
            join(u, v);
            total_cost += cost;
        }
    }

    for(int i = 0; i<n; i++){
        total_cost += graph[i].top() * (colors[i] -1);
    }

    cout << total_cost << endl;


    

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1;  cin >> t;
    while(t--){
        init_dsu();
        solve();
    }
}