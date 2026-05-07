/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000LL
#define pll pair<ll, ll>

using Project = pair<pll, ll>;

// TODO: do this problem


int solve(){
    int n; cin >> n;
    vector<Project> projects;
    for(int i = 0; i < n; i++){
        ll a, b, c; cin >> a>> b >>c;
        projects.push_back({{a, b}, c});
    }
    sort(projects.begin(), projects.end());
    
    vector<ll> dp(n, 0);
    
    for(int i = n-1; i >= 0; i--){
        
        dp[i] = i + 1 < n ? dp[i+1] : 0;
        ll end_time = projects[i].first.second;

        ll candidate = projects[i].second;
        int iter_candidate = lower_bound(projects.begin(), projects.end(), Project({make_pair(end_time+1, (ll)0), (ll)0})) - projects.begin();
        if(iter_candidate < n){
            candidate += dp[iter_candidate];
        }
        dp[i] = max(dp[i], candidate);
    }
    
    cout << dp[0] << endl;

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