/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    ll n; 
    cin >> n;
    ll min_positive = 1e17;
    vector<ll> picked;
    for(int i = 0; i < n; i++){
        ll val;
        cin >> val;
        if(val <= 0) picked.push_back(val);
        if(val > 0 and val < min_positive) min_positive = val;
    }
    ll can_positive = true;
    sort(picked.begin(), picked.end());
    for(int i = 0; i+1 < picked.size(); i++){
        can_positive &= (abs(picked[i] - picked[i+1]) >= min_positive);
    }
    can_positive &= min_positive < 1e17;

    cout << picked.size() + can_positive << endl;
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