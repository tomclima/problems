/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    ll n, x; cin >> n >> x;
    
    vector<ll> a(n); 
    vector<ll> b(n); 
    vector<ll> c(n); 

    for(int i = 0; i < n; i++){
        ll q, w, e; cin >> q >> w >> e;
        a[i] =q;
        b[i] = w;
        c[i] = e;
    }

    ll curr = 0;
    for(int i = 0; i < n; i++){
        curr += a[i] *(b[i] -1);
    }

    ll best = 2000000000000000000;
    bool all_terrible = true;
    for(int i = 0; i < n; i++){
        all_terrible = false; 
        ll profit = a[i] * (b[i]) - c[i];
        if(curr >= x){
            best = 0;
        }
        else if(profit > 0){
            ll rollbacks = ceil((double)max((x - curr), (ll)0)/profit);
            if (rollbacks < best) best = rollbacks;

        }
    }

    if(best == 2000000000000000000) best = -1;
    cout << best<< endl;

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