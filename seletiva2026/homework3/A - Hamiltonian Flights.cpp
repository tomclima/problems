/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

ll MOD = 1e9 + 7;

int solve(){
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
    }

    vector<vector<ll>> dp(n, vector<ll>(1<<n, 0)); // bitmasked
    dp[0][1] = 1;
    queue<pair<int, ll>> queue;
    queue.push({0, 1});
    while(!queue.empty()){
        auto [v, set] = queue.front(); queue.pop();
        if(v == n-1) continue;
        for(auto i : graph[v]){
            if(!(set & (1 << i)) and i < n){
                    dp[i][set | (1 << i)] = (1 + dp[i][set | (1 << i)]) % MOD; 
                queue.push({i, set | (1<<i)});
            }
        }
    }

    
    cout << dp[n-1][(1<<n) -1] % MOD;

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