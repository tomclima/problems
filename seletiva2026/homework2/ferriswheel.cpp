/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    ll n; cin >> n;
    ll x; cin >> x;
    vector<ll> arr;
    for(int i  = 0; i < n; i++){
        ll val; cin >> val;
        arr.push_back(val);
    }

    sort(arr.begin(), arr.end());

    int i = 0;
    int j = n-1;
    int buckets = 0;
    while(i <= j){
        
        if( i!= j and arr[i] + arr[j] <= x){
            i++;
        }
        j--;
        buckets++;
    }

    cout << buckets;
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