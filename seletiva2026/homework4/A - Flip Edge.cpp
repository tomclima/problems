/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pll pair<ll, ll>


ll INF = 1e15;
int solve(){
    
    int n, m; cin >> n >> m;
    ll x; cin >> x;

    vector<vector<pll>> graph(2*n); // first n positions are normal edges, last n are reversed

    for(int i = 0; i < n; i++){
        graph[i].push_back({x, n+i});
        graph[n+i].push_back({x, i});
    }

    for(int i = 0; i < m; i++){
        ll u, v; cin >> u >> v;
        u--;
        v--;
        graph[u].push_back({1, v});
        graph[n+v].push_back({1, n+u});
    }
    
    vector<ll> dist(2*n, INF);
    priority_queue<pll, vector<pll>, greater<pll>> queue;
    queue.push({0, 0});
    dist[0] = 0;

    while(!queue.empty()){
        
        auto [d, v] = queue.top();
        queue.pop();
        if(d > dist[v]) continue;

        for(auto [dw, w] : graph[v]){
            if(dist[w] > dw + d){
                dist[w] = dw + d;
                queue.push({dist[w], w});
            }
        }
    }

    cout << min(dist[n-1], dist[2*n-1]) << endl;

    

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}