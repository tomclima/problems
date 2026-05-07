/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int len_p, len_s; cin >> len_p >> len_s;
    ll add, rem, mod; cin >> add >> rem >> mod;
    string p, s; cin >> p >> s;

    if(mod > add + rem) mod = add + rem;

    vector<vector<ll>> dp(len_s+1, vector<ll> (len_p + 1, 0));
    dp[0][0] = 0;
    for(int i = 1; i <= len_s; i++){
        dp[i][0] = i*add;
    }
    for(int j = 1; j <= len_p; j++){
        dp[0][j] = j*rem;
    }

    for(int i = 1; i <= len_s; i++){
        for(int j = 1; j <= len_p; j++){
            ll c_add = dp[i-1][j] + add;
            ll c_rem = dp[i][j-1] + rem;
            ll c_mod = dp[i-1][j-1] + mod*(s[i-1] != p[j-1]);
            dp[i][j] = min(min(c_add, c_rem), c_mod); 
        }
    }

    cout << dp[len_s][len_p] << endl;

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