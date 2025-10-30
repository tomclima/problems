/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){

    int n; cin >> n;
    vector<ll> arr;
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        arr.push_back(val);
    }

    vector<ll> prefix_min;
    ll min_so_far = 1e18;
    for(auto &num : arr){
        if(num < min_so_far) min_so_far = num;
        prefix_min.push_back(min_so_far);
    }

    vector<ll> suffix_max;
    ll max_so_far = -1e18;
    for(int i = arr.size() -1; i >= 0; i--){
        if(arr[i] > max_so_far) max_so_far = arr[i];
        suffix_max.push_back(max_so_far);
    }
    reverse(suffix_max.begin(), suffix_max.end());

    for(int i = 0; i < n; i++){
        if(arr[i] > prefix_min[i] and arr[i] < suffix_max[i]) cout << "0";
        else cout << "1"; 
    }
    cout << endl;
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