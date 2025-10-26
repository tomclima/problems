/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int



int solve(){
    ll n, m, l; cin >> n >> m >> l;

    queue<pair<ll, ll>> hurdles; // [l, r] inclusive ranges
    for(int i = 0; i < n; i++){
        ll left, right; cin >> left >> right;
        hurdles.push({left, right});
    }
    queue<pair<ll, ll>> powerups;
    for(int i = 0; i < m; i++){
        ll xi, vi; cin >> xi >> vi;
        powerups.push({xi, vi});
    }
    
    priority_queue<ll> found_powerups;
    ll jumping_power = 1;
    bool possible = true;
    ll cnt = 0;
    for(int i = 0; (i < m+n) and possible; i++){ 
        pair<ll, ll> powerup = powerups.front();
        pair<ll, ll> hurdle = hurdles.front();
        if(powerups.empty()) powerup = {1e18, 1e18};
        if(hurdles.empty()) hurdle = {1e18, 1e18};
        if(powerup.first < hurdle.first){
            found_powerups.push(powerup.second);
            powerups.pop();
        }
        else{
            ll diff = hurdle.second - hurdle.first + 2;
            while(diff > jumping_power and found_powerups.size() > 0){
                jumping_power += found_powerups.top();
                found_powerups.pop();
                cnt++; // add to the power up count
            }
            if(diff > jumping_power) possible = false;
            hurdles.pop();
        }


    }   

    if(!possible) cnt = -1;

    cout << cnt << endl;

    return 0;
}

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }
}