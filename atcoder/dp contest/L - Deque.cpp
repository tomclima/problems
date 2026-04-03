/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

// minmax dp

ll recurse(int i, int j, vector<ll> &a, vector<vector<ll>> &dp){
    if(dp[i][j] != -1) return dp[i][j];
    if(i == j) return dp[i][j] = a[i];

    dp[i][j] = 0;

    dp[i][j] = max(a[j] - recurse(i, j-1, a, dp), a[i] - recurse(i+1, j, a, dp));
    
    
    return dp[i][j];
}

int solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    vector<vector<ll>> dp(n, vector<ll> (n, -1));
        
    cout << recurse(0, n-1, a, dp) << endl;
    
    

    
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