/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int



int solve(const vector<ll> &preprocess){
    int left, right; cin >> left >> right;
    ll i1 = lower_bound(preprocess.begin(), preprocess.end(), left) - preprocess.begin();
    ll i2 = upper_bound(preprocess.begin(), preprocess.end(), right) - preprocess.begin() -1;
    cout << i2 - i1 +1 << endl;
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll limit = 500000;
    
    vector<ll> preprocess(limit);
    for(ll i = 0; i < limit; i++){
        preprocess[i] = (i*i*i + 3*i*i + 3*i);
    }
    
    

    ll t = 1;  cin >> t;
    while(t--){
        solve(preprocess);
    }
}