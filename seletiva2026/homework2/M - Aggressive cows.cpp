/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000



bool check(ll dist, int cows, vector<ll> &prefix){

    int remaining = cows;
    auto iter = prefix.begin();
    while(iter != prefix.end() and remaining > 0){
        remaining--;
        iter = lower_bound(prefix.begin(), prefix.end(), *iter+dist);
    }

    if(remaining > 0) return true;
    return false;
}

int solve(){
    int n, c; cin >>n >> c;
    vector<ll> stalls(n);
    for(auto &i : stalls) cin >> i;
    sort(stalls.begin(), stalls.end());

    ll l = 0; ll r = 10000000000;
    while(l < r){
        ll mid = l + (r - l)/2;
        if(check(mid, c, stalls)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    cout << l-1 << endl;
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