/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 10000000000000

int solve(){
    int n, m; cin >> n >> m;
    vector<tuple<ll, int, int>> edges;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({c, a-1, b-1});
    }
    
    
    vector<int> parent(n, -1);
    vector<ll> dist(n, 0);
    
    dist[0] = 0;
    parent[0] = 0;
    for(int i = 0; i < n-1; i++){
        for(auto [cost, u, v] : edges){
            if(dist[u] + cost < dist[v]){
                parent[v] = u;
                dist[v] = dist[u] + cost;
            }
        }
    }
    // check for cycles

    int cycle_node = -1;
    for(auto [cost, u, v] : edges){
        if(dist[u] + cost < dist[v]){
            parent[v] = u;
            cycle_node = v;
            dist[v] = dist[u] + cost;
        }
    }

    // if has no cycles
    if(cycle_node == -1){
        cout << "NO" << endl;
        return 0;
    }


    // if has cycles
    cout << "YES" << endl;

    int curr_node = cycle_node;
    for(int i = 0; i < n; i++){
        curr_node = parent[curr_node];
    }

    vector<bool> visited(n, 0);
    vector<int> ans;
    while(!visited[curr_node]){
        visited[curr_node] = true;
        ans.push_back(curr_node);
        curr_node = parent[curr_node];
    }
    ans.push_back(curr_node);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i]+1 << " ";
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