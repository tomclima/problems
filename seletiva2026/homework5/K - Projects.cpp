/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000LL
#define pll pair<ll, ll>

// TODO: do this problem

ll recurse(int n, vector<ll> &dp, vector<pair<pll, ll>> &projects){
    
    if(n < 0) return 0;
    if(dp[n] != -1) return dp[n];

    auto [p, val] = projects[n];
    auto [end, begin] = p;

    dp[n] = recurse(n-1, dp, projects);
    
    // find first that ends before the start
    int it = upper_bound(projects.begin(), projects.end(), make_pair(make_pair(begin, MAXN),MAXN)) - projects.begin();
    it--;
    dp[n] = max(dp[n], val + recurse(it, dp, projects));
    return dp[n];
    return 0;
}

int solve(){
    int n; cin >> n;
    vector<pair<pll, ll>> projects;
    for(int i = 0; i < n; i++){
        ll a, b, c; cin >> a>> b >>c;
        projects.push_back({{b, a}, c});
    }
    projects.push_back({{0LL, 0LL}, 0LL});
    sort(projects.begin(), projects.end());
    vector<ll> dp(n+1, -1);
    dp[0] = 0;
    
    ll max_val = recurse(n-1, dp, projects);
    cout << max_val;

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