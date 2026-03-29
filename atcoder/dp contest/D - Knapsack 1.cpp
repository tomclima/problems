/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<int, int>

int recurse(int n, int w, vector<vector<int>> &dp, vector<pii> &obj){
    if(w <= 0) return 0;
    if(n < 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];

    dp[n][w] = max(recurse(n-1, w, dp, obj), recurse(n-1, w-obj[n].second, dp, obj) + obj[n].first);
    return dp[n][w];
}

int solve(){
    int n, w; cin >> n >> w;
    vector<pii> objects(n);
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        objects[i] = {a, b};
    }

    vector<vector<int>> dp(n, vector<int> (w+1, 0));

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