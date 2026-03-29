/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000




int solve(){
    int n, k; cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >>h[i];

    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for(int i = 2; i < n; i++){
        int min_cost = 1000000001;
        for(int j = 1; j <= k and i-j >= 0; j++){
            min_cost = min(dp[i-j] + abs(h[i-j] -h[i]), min_cost);
        }
        dp[i] = min_cost;
    }
    
    cout << dp.back() << endl;

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