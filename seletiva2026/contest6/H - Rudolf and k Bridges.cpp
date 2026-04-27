/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    ll n, m, k, d; cin >> n >> m >> k >> d;

    vector<vector<ll>> cost(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int c; cin >> c;
            cost[i].push_back(c+1);
        }
    }
    
    vector<vector<ll>> dp_cost(n, vector<ll> (m, -1));
    for(int i = 0; i < n; i++){
        dp_cost[i][0] = 1;
        multiset<ll> min_cost {1};
        for(int j = 1; j < m; j++){
            if(min_cost.size() > d+1){
                min_cost.erase(min_cost.find(dp_cost[i][j-d-2]));
            }
            dp_cost[i][j] = cost[i][j] + *min_cost.begin();
            min_cost.insert(dp_cost[i][j]);
        }
    }

    vector<ll> prefix_cost(n+1, 0);
    for(int i = 1; i <= n; i++){
        prefix_cost[i] = dp_cost[i-1][m-1] + prefix_cost[i-1];
    }

    ll min_cost = MAXN;
    for(int i = 0; i + k <= n; i++){
        min_cost = min(prefix_cost[i+k] - prefix_cost[i], min_cost);
    }

    cout << min_cost << endl;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}