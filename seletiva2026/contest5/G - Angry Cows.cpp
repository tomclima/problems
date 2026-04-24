/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

ll MAXN = (ll)1000000000000000000;

bool check(ll radius, int k, vector<ll> cows){

    auto curr = cows.begin();
    while(curr != cows.end() and k--){
        curr = upper_bound(cows.begin(), cows.end(), (*curr)+2*radius);
    }   
    if(curr == cows.end()) return true;
    
    return false;
}

int solve(){
    int n, k; cin >> n >> k;
    vector<ll> a(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    
    ll l = 0;
    ll r = MAXN;
    while(l < r){
        ll mid = l + (r - l)/2;
        if(check(mid, k, a)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    cout << l << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("angry.in", "r", stdin); freopen("angry.out", "w", stdout);
    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}