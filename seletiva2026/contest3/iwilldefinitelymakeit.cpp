/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

bool check(const vector<ll> &towers, int mid, int index, ll water){
    if(towers[mid] - towers[index] > towers[index] - water) return true;
    else{
        return false;
    }
}

int solve(){
    int n, k; cin >> n >> k;
    vector<ll> towers;
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        towers.push_back(val);
    }
    ll k_val = towers[k-1];


    sort(towers.begin(), towers.end());
    towers.push_back(1e18);
    k = lower_bound(towers.begin(), towers.end(), k_val) - towers.begin();
    ll water = 0;
    while (k != towers.size() - 1){
        ll l = k;
        ll r = towers.size()-1;
        ll ans;
        while (l <= r){
            ll middle = (r + l)/2;
            if (check(towers, middle, k, water)){
                r = middle -1;
                ans = middle;
            }
            else{
                l = middle+1;
            }
        }
        if(k == ans-1) break;
        water += towers[ans-1] - towers[k];
        k = ans-1;

    }

    if(towers[k] == towers[n-1]) cout << "yes";
    else cout << "No";
    cout << endl;
    
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