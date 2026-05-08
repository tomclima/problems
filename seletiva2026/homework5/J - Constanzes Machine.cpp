/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

ll MOD = (ll)1000000000+7;

ll fib(int n, vector<ll> &dp){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(dp[n] != -1) return dp[n];

    return dp[n] = (fib(n-1, dp) % MOD + fib(n-2, dp) % MOD) % MOD;
}

int solve(){
    string s; cin >> s;
    vector<ll> islands;

    s.append("!n!");
    int island_size = 0;
    bool found_bad = 0;
    for(int i = 0; i < s.size(); i++){
        
        if(s[i] == 'm' or s[i] =='w') found_bad = true;
        
        if((s[i] == 'n' or s[i] == 'u')){
            if(s[i] == s[i+1]) island_size++;
            else{
                islands.push_back(island_size+1);
                island_size = 0;
            }
        } 
    }
    

    vector<ll> dp(1000000, -1);

    ll prod = !found_bad;
    for(int i = 0; i < islands.size(); i++){
        prod = (prod % MOD * fib(islands[i], dp) % MOD) % MOD;
    }
    
    cout << prod << endl;
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