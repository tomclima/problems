/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

bool check(ll mana, const vector<ll> &arr){
    for(auto val : arr){
        mana += val;
        if (mana < 0) return false;
    }
    return true;
}

int solve(){
    ll n; cin >> n;
    vector<ll> arr;
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        arr.push_back(val);
    }
    // closed interval [lo, hi]
    ll l = 0;
    ll r = 1e18;
    while (l <= r){
        ll middle = l + (r - l)/2;
        if (check(middle, arr)){
            r = middle-1;
        }
        else{
            l = middle+1;
        }
    }

    cout << l << endl;  
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