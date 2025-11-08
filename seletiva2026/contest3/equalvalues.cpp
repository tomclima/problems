/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int

int solve(){
    int n; cin >> n;
    vector<ll> vec;
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        vec.push_back(val);
    }

    vector<pair<ll, ll>> islands;
    ll curr_l = 0;
    ll curr_r = 0;
    for(int i = 0; i+1 < n; i++){
        if(vec[i] == vec[i+1]) curr_r = i+1;
        else{
            islands.push_back({curr_l, curr_r});
            curr_l = i+1;
            curr_r = i+1;
        }
    }
    islands.push_back({curr_l, curr_r});

    ll min_cost = 1e18;
    for(auto island : islands){
        if(vec[island.first]*island.first + vec[island.second]*(n - island.second -1) < min_cost){
            min_cost = vec[island.first]*island.first + vec[island.second]*(n - island.second -1);
        }
    }

    cout << min_cost << endl;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;  cin >> t;
    while(t--){
        solve();
    }
}