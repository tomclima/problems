/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 10000000000000

vector<ll> dp;
vector<ll> heights;
int k;

ll get_cost(int n){
    if(dp[n] != -1) return dp[n];
    if(n == 0) return 0;

    ll cost = LLONG_MAX;
    for(int i = max(n-k, 0); i < n; i++){
        cost = min(cost, get_cost(i) + abs(heights[i] - heights[n]));
    }

    return dp[n] = cost;

}


int solve(){

    int n; cin >> n >> k;

    for(int i = 0; i < n; i ++){
        int val; cin >> val;
        heights.push_back(val);
        dp.push_back(-1);
    }

    ll val = get_cost(n-1);
    cout << val;




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