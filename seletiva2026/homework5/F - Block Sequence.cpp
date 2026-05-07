/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;

    vector<int> dp(n);

    for(int i = n-1; i >= 0; i--){
        
        dp[i] = i+1 < n ? dp[i+1] : 0;
        int candidate = 0;
        if(i + a[i] < n){
            candidate = a[i] + 1;
            if(i + a[i] + 1 < n) candidate += dp[i+a[i]+1];
        }
        dp[i] = max(dp[i], candidate);
    }

    cout << n - dp[0] << endl;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}