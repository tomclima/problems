/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

vector<ll> pref;

ll mod = (ll)1000000000+7;


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
    vector<vector<ll>> dp(n+1, vector<ll> (k+1, 0));
    vector<vector<ll>> prefix(n+1, vector<ll> (k+2, 1));

    for(int i = 0; i <=n; i++){
        dp[i][0] = 1;
        prefix[i][0] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= k; j++){
            dp[i][j] = (((prefix[i-1][j+1] - prefix[i-1][j-min((ll)j, a[i-1])]) % mod) + mod) % mod;
            prefix[i][j+1] = (prefix[i][j] + dp[i][j]) % mod;
        }
    }

    cout << dp[n][k] << endl;

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