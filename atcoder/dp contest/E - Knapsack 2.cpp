/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<ll, ll>

ll recurse(int n, int w, vector<map<ll, ll>> &dp, vector<pii> &obj){
    if(w <= 0) return 0;
    if(n < 0) return 0;
    if(dp[n].find(w) != dp[n].end()) return dp[n][w];
    
    // check if it is in stable region
    auto it_upper  = dp[n].upper_bound(w);
    it_upper--;
    auto it_lower = it_upper;
    it_upper++;

    if(it_lower->second == it_upper->second){
        return dp[n][w] = it_lower->second;
    }
    

    dp[n][w] = max(recurse(n-1, w, dp, obj), (w- obj[n].first >= 0) ? recurse(n-1, w-obj[n].first, dp, obj) + obj[n].second : 0);
    return dp[n][w];
}

int solve(){
    ll n, w; cin >> n >> w;
    vector<pii> objects(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        objects[i] = {a, b};
    }

    sort(objects.begin(), objects.end());
    vector<map<ll, ll>> dp(n);
    ll sum_w = 0;
    ll sum_val = 0;
    int i = 0;
    for(auto obj : objects){
        sum_w += obj.first;
        sum_val += obj.second;
        dp[i][0] = 0;
        dp[i][sum_w] = sum_val;
        if(w > sum_w){
            dp[i][w] = sum_val;
        }
        i++;
    }
    cout << recurse(n-1, w, dp, objects) << endl;

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