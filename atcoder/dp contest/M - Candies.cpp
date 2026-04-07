/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

vector<ll> pref;

ll mod = (ll)1000000000+7;

ll recurse(int n, int k, vector<ll> &a, vector<vector<ll>> &dp){
    if(n < 0) return 0;
    if(k <= 0) return 0;
    if(k > pref[n+1]) return dp[n][k] = 0;
    if(n == 0) return dp[n][k] = 1;
    if(dp[n][k] != -1) return dp[n][k];

    dp[n][k] = recurse(n-1, k, a, dp);
    for(int i = 1; i <= a[n]; i++){
        dp[n][k] = (dp[n][k] + recurse(n-1, k-i, a, dp)) % mod;
    }

    return dp[n][k];
}

int solve(){
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    pref.push_back(0);
    for(auto &i : a) {
        cin >> i;
    }
    
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for(auto i : a){
        pref.push_back(pref.back() + i);
    }
    vector<vector<ll>> dp(n, vector<ll> (k+1, -1));
    cout << recurse(n-1, k, a, dp) << endl;

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