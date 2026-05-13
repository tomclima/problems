/*please*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

ll MOD = 1e9 + 7;

ll topdown(ll node, ll set, vector<vector<ll>> &dp, vector<vector<int>> &graph){
    if(dp[set][node] != -1) return dp[set][node];
    if(!(set & (1 << node))) return dp[set][node] = 0;
    if(node != graph.size()-1 and set & (1 << graph.size()-1)) return 0;
    
    ll val = 0;
    for(auto w : graph[node]){
        if(!(set & (1 << w))) continue;
        int altered_set = (set ^ (1 << node));
        val = (val % MOD + topdown(w, altered_set, dp, graph) % MOD) % MOD;
    }

    return dp[set][node] = val;
}

int solve(){
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if(a == b) continue;
        if(a ==n) continue;
        
        graph[b-1].push_back(a-1);
    }


    
    vector<vector<ll>> dp(1 << n, vector<ll>(n, -1)); // bitmasked

    dp[1][0] = 1;


    ll ans = topdown(n-1, (1 << n) - 1, dp, graph);
    cout << ans << endl;


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