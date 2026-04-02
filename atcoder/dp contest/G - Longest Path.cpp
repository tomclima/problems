/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int recurse(int v, vector<vector<int>> &g, vector<int> &dp){
    if(dp[v] != -1) return dp[v];
    if(g[v].empty()) return dp[v] = 0;

    dp[v] = 0;
    for(auto w : g[v]){
        dp[v] = max(dp[v], recurse(w, g, dp));
    }
    return dp[v] = dp[v] + 1;
}

int solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> dp(n, -1);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
    }

    int longest = -1;
    for(int i = 0; i < n; i++){
        longest = max(longest, recurse(i, graph, dp));
    }

    cout << longest << endl;

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