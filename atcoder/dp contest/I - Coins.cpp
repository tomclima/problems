/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define ld long double

/*
    os estados da nossa dp são da forma f(coins, plus)
    coins vai de [0 a n]
    ou seja, referenciamos p[n-1]
    plus vai de -n a n
    traduzimos os estados somando n ao estado. estado -n := 0, estado n := 2n
    
*/

ld recurse(int coins, int plus, vector<ld> &p, vector<vector<ld>> &dp){
    int i = plus + p.size(); // what we use to access indices
    int coin_index = coins-1; // what we use to access indices
    if(plus > coins) return 0;
    if (plus < -coins ) return 0;
    if(coins <= 0) return 1;
    if(dp[coin_index][i] > -1) return dp[coin_index][i];

    return dp[coin_index][i] = recurse(coins-1, plus+1, p, dp)*(1 - p[coin_index]) + recurse(coins-1, plus-1, p, dp)*p[coin_index];
}

int solve(){
    int n; cin >> n;
    vector<ld> p(n);
    for(auto &i : p) cin >> i;
    vector<vector<ld>> dp(n, vector<ld> (2*n+1, -1));

    ld total_chance = 0;
    for(int i = 1; i <= n; i++){
        total_chance += recurse(n, i, p, dp);
    }  

    cout << setprecision(12) << fixed << total_chance << endl;

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