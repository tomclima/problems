/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

ll gcd(ll a, ll b){
    if(min(a, b) == 0) return max(a, b);
    if(min(a, b) > 0) return gcd(max(a, b) - min(a, b), min(a, b));
}

ll lcm(ll a, ll b){
    return a * b/gcd(a, b);
}

int solve(){
    int n; cin >> n;

    vector<ll> essences;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        ll last_gcd = 0;
        for(int j = 0; j < a; j++){
            ll val; cin >> val;
            ll last_gcd = gcd(val, last_gcd);
        }
        essences.push_back(last_gcd);
    }

    sort(essences.begin(), essences.end());
    essences.pop_back();
    ll last_harmony = 1;
    for(int i = 0; i < n; i++){
        last_harmony = lcm(last_harmony, essences[i]);
    }

    cout << last_harmony << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; t = 1;//cin >> t;
    while(t--){
        solve();
    }
}