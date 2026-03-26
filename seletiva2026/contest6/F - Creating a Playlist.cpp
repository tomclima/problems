/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

ll UNINITUALIZED = -12345678910;

ll max_good(int i, int k, vector<ll> &dp, vector<ll> &songs){
    if(i < 0) return 0;
    if(dp[i] != UNINITUALIZED) return dp[i];

    if(i - k < 0) dp[i] = max((ll)0, songs[i]);
    else{
        dp[i] = max(max_good(i-k, k, dp, songs), max_good(i-k, k, dp, songs) + songs[i]);
    }
    if(i > 0){
        dp[i] = max(dp[i-1], dp[i]);
    }
    return dp[i];
}

int solve(){
    int n, k; cin >> n >> k;
    vector<ll> dp(n, UNINITUALIZED), songs(n);
    for(auto &i :songs) cin >> i;

    for(int i = 0; i < n; i++){
        max_good(i, k, dp, songs);
    }

    cout << dp[n-1] << endl;

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