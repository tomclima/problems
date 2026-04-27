/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pll pair<ll, ll>
int solve(){
    int n, m, k; cin >> n >> m >> k;
    
    vector<vector<pll>> graph(n+k); // first n elements are cities, last k elements are teleporters
    for(int i = 0; i < m; i++){
        ll a, b, c; cin >> a >> b >> c;
        graph[a-1].push_back({c, b-1});
        graph[b-1].push_back({c,a-1});
   }

    for(int i = 0; i < n; i++){
        int t; cin >> t;
        for(int j = 0;j < t; j++){
            int tele, cost; cin >> tele >> cost;
            graph[i].push_back({cost, n+tele-1});
            graph[n+tele-1].push_back({0, i});
        }
    }

    // djikstra
    priority_queue<pll, vector<pll>, greater<pll>> heap;
    vector<ll> cost(n + k, MAXN);
    cost[0] = 0;
    heap.push({0, 0});
    while(!heap.empty()){
        
        auto [w, v] = heap.top();
        heap.pop();
        if(w > cost[v]) continue;

        for(auto [c, u] : graph[v]){
            if(cost[u] > w + c){
                cost[u] = w + c;
                heap.push({cost[u], u});
            }
        }
    }

    cout << cost[n-1] << endl;

    

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