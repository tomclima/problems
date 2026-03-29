/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000




int solve(){
    int n; cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >>h[i];

    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for(int i = 2; i < n; i++){
        for(int j = 1; j <= 100; j++){
            dp[i] = min(dp[i-1] + abs(h[i-1] -h[i]), dp[i-2] + abs(h[i-2] - h[i]));
        }
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