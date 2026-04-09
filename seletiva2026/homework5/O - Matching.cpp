/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pll pair<ll, ll>

ll mod = (ll)1000000000+7;

pll recurse(int v, vector<pll> &dp, vector<vector<int>> &g, vector<bool> &vis){
    if(dp[v] != make_pair((ll)0, (ll)0)) return dp[v];
    
    ll white = 1;
    ll black = 1;
    for(auto w : g[v]){
        if(vis[w]) continue;
        vis[w] = true;
        white = (white * (recurse(w, dp, g, vis).first + recurse(w, dp, g, vis).second)) % mod;
        black = (black * (recurse(w, dp, g, vis).first)) %mod;
    }
    return dp[v] = {white, black};
}

int solve(){
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<pll> dp(n, {0,0});
    vector<bool> vis(n, false);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    vis[0] = true;
    pll root = recurse(0, dp, g, vis);
    cout << (root.first + root.second) % mod  << endl;

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