/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

ll INF = (ll)5000000000000;

ll recurse(int i, int j, vector<ll> &a, vector<ll> &p, vector<vector<ll>> &dp){
    if(i >= j) return 0;
    if(j == i+1) return dp[i][j] = a[i] + a[j];
    if(dp[i][j] != 0) return dp[i][j];
    dp[i][j] = INF;
    for(int k = 0; k < j - i; k++){
        ll psum1 = p[j-k] - p[i];
        ll psum2 = p[j] - p[j-k];
        ll candidate = recurse(i, j-k-1, a, p, dp) + psum1 + recurse(j-k, j, a ,p, dp) + psum2 +  a[j];
        dp[i][j] = min(dp[i][j], candidate);
    }

    return dp[i][j];
}

int solve(){
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> prefix{0};
    for(auto &i : a) {
        cin >> i;
        prefix.push_back(prefix.back() + i);
    }


    vector<vector<ll>> dp(n, vector<ll> (n, 0));
    
    cout << recurse(0, n-1, a, prefix, dp);


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