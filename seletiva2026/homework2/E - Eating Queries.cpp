/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n, q; cin >> n >> q;
    vector<ll> candies(n);
    for(auto &i : candies) cin >> i;
    vector<ll> prefix(n+1);
    sort(candies.begin(), candies.end());
    reverse(candies.begin(), candies.end());
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + candies[i-1];
    }
    for(int i = 0; i < q; i++){
        ll a; cin >> a;
        int ans = lower_bound(prefix.begin(), prefix.end(), a) - prefix.begin();
        if(ans == prefix.size()) cout << -1 << endl;
        else cout << ans << endl;

    }
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}