/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pll pair<ll, ll>

ll INF = 1e15;

ll wait(int v, int d, vector<pll> &traffic){
    
    auto [red, green] = traffic[v];

    ll total_cycle = red + green;
    ll cycle_pos = d - (total_cycle * (d /total_cycle));
    
    ll wait = total_cycle - cycle_pos;
    
    if(wait > green) return 0;
    
    return wait;
}

int solve(){
    int n, m; cin >> n >> m;
    vector<pll> traffic(n);
    
    for(int i = 0; i< n; i++){
        ll a, b; cin >> a >> b;
        traffic[i] = {a, b};
    }

    vector<vector<pll>> graph(n);
    for(int i = 0; i <m; i++){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }

    priority_queue<pll, vector<pll> ,greater<pll>> queue;
    vector<ll> dist(n, INF);
    dist[0] = 0;
    queue.push({0, 0});
    while(!queue.empty()){
        
        auto [d, v] = queue.top();
        queue.pop();
        if(d > dist[v]) continue;

        for(auto [dw, w] : graph[v]){
            
            ll wait_time = wait(v, d, traffic);
            if(dist[w] > d + wait_time + dw){
                dist[w] = d + wait_time + dw;
                queue.push({dist[w], w});
            }
        }
    }


    cout << dist[n-1] << endl;
    
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