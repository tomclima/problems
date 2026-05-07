/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000LL

int solve(){
    int n; cin >> n;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;

    /*
        contest: 1 or 4
        sport: 3 or 4

        dp[0][j] -> rest at day j
        dp[1][j] -> contest at day j
        dp[2][j]-> sport at day j

    */

    vector<vector<ll>> dp(3, vector<ll> (n+1, MAXN));
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[2][0] = 0;
    for(int i = 1; i <= n; i++){
        
        // rest
        dp[0][i] = min(dp[2][i-1],min(dp[0][i-1], dp[1][i-1])) + 1;

        // contest
        dp[1][i] = a[i-1] == 1 or a[i-1] == 3 ? min(dp[0][i-1], dp[2][i-1]) : MAXN;

        // sport
        dp[2][i] = a[i-1] ==2 or a[i-1] == 3 ? min(dp[0][i-1], dp[1][i-1]) : MAXN;
    }


    cout << min(dp[2][n], min(dp[0][n], dp[1][n])) << endl;
    
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
}