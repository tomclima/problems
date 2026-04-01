    /*link*/
     
    #include <bits/stdc++.h>
    using namespace std;
    #define endl '\n'
    #define ll long long int
    #define MAXN 1000000000000000000
     
    ll mod = (ll)998244353;
     
    ll recurse(int i, ll prev, vector<map<ll, ll>> &dp, vector<vector<ll>> &g, vector<ll> &v){
        if(dp[i].find(prev) != dp[i].end()) return dp[i][prev];
        if(g[i].size() == 0) return dp[i][prev] = 0;
     
        dp[i][prev] = 0;
        if(prev == -1){
            for(auto &a : g[i]){
                dp[i][prev] = (dp[i][prev] + 1 + recurse(a, v[i], dp, g, v)) % mod;
            }
        }
        else{
            for(auto &a : g[i]){
                if(v[a] == v[i] + prev){
                    dp[i][prev] = (dp[i][prev] + 1 + recurse(a, v[i], dp, g, v)) % mod;
                }
            }
        }
     
        return dp[i][prev];
    }
     
     
    int solve(){
        int n, m; cin >> n >> m;
        vector<ll> vertices(n);
        vector<vector<ll>> graph(n);
        for(ll  &i : vertices) {
            cin >> i;
        }
        for(int i = 0; i < m; i++){
            int a, b; cin >> a>> b;
            graph[a-1].push_back(b-1);
        }
     
        vector<map<ll, ll>> dp(n);
     
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum = (sum + recurse(i, -1, dp, graph, vertices)) % mod;
        }
     
        cout << sum << endl;
        return 0;
    }
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int t = 1; cin >> t;
        while(t--){
            solve();
        }
    }