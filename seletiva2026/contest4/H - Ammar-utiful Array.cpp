/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


ll bsearch(ll target, ll increase, vector<ll> &color_prefix){
    
    ll l = 0;
    ll r = color_prefix.size();
    while(l < r){
        int mid = (l + r)/2;
        if(color_prefix[mid] + mid*increase > target){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    return l-1;
}

int solve(){
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> c(n);
    for(auto &i : a) cin >> i;
    for(auto &i: c) cin >> i;

    map<int, ll> color_undo_increase;
    map<int, vector<ll>> color_prefix;
    

    for(int i = 0; i < n; i++){
        if(color_prefix[c[i]].empty()) color_prefix[c[i]].push_back(0);
        color_prefix[c[i]].push_back(color_prefix[c[i]].back() +  a[i]);
    }

    int q; cin >> q;
    ll total_increase = 0;
    for(int i = 0; i < q; i++){
        ll op, col, x; cin >> op >> col >> x;
        if(op ==1){
            total_increase += x;
            color_undo_increase[col] += x;
        }
        if(op == 2){
            int n = bsearch(x, total_increase - color_undo_increase[col], color_prefix[col]);
            cout << n << endl;
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}