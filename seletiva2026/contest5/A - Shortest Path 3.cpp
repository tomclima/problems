/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 3000000000000000

int solve(){
    int n, m; cin >> n >> m;
    vector<ll> dist(n+1, LLONG_MAX);
    vector<vector<tuple<ll, ll>>> adj(n+1);
    priority_queue<tuple<ll, ll>, vector<tuple<ll, ll>>, greater<tuple<ll, ll>>> pq;
    
    vector<ll> vertex_weights;
    for(int i = 0; i <n; i++){
        ll val; cin >> val;
        vertex_weights.push_back(val);
    }

    for(int i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        adj[a-1].push_back({b-1, vertex_weights[a-1] + c});
        adj[b-1].push_back({a-1, vertex_weights[b-1] + c});
    }

    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();

        if(d <= dist[v]){
            for(auto [u, w] : adj[v]){
                if(dist[u] > dist[v] + w){
                    dist[u] = dist[v] + w;
                    pq.push({dist[u], u});
                }
            }
        }
    }

    for(int i = 1; i < n; i++){
        cout << dist[i] + vertex_weights[i] << " ";
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