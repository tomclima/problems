/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(auto &i: a) cin >> i;

    vector<ll> ans = a;
    for(int i = 30; i >= 0; i--){
        
        ll spent = 0;
        vector<ll> aux = ans;
        for(auto &j : aux){
            
            if (!(j & (1 << i))) spent ++;
            j |= (1 << i);
        }
        if(spent <= k){
            k -= spent;
            ans = aux;
        }
    }

    ll max_and = ans[0];
    for(int i = 0; i < n; i++){
        max_and &= ans[i];
    }


    cout << max_and << endl;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}