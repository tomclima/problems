/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000LL
#define MOD 998244353LL

int recurse(int v, vector<ll> &dp, vector<vector<int>> &graph){
    
    if(dp[v] != -1) return dp[v];

    dp[v] = 1;
    for(auto w : graph[v]){
        dp[v] = (dp[v] + recurse(w, dp, graph) % MOD) %MOD;
    }

    return dp[v] % MOD;
}


int solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);

    // graph of commanders. a is commander of bs
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
    }

    vector<ll> dp(n, -1);
    cout << recurse(0, dp, graph) -1 << endl;

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