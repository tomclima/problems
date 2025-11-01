/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    ll n, t; cin >> n >> t;

    bool has_0 = false;
    vector<ll> negatives;
    vector<ll> positives;
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        
        if(val == 0) has_0 = true;

        else if(val < 0) negatives.push_back(-1*val);
        else if (val > 0) positives.push_back(val);
    }

    reverse(negatives.begin(), negatives.end());

    ll total_buses_negative = 0;

    for(int i = 0; i < negatives.size(); i++){
        
        if(negatives[i] > t) break;
        
        ll remaining_seconds = t - 2*negatives[i];

        ll negative_buses = i+1;
        
        ll find = upper_bound(positives.begin(), positives.end(), remaining_seconds) - positives.begin() -1;

        ll positive_buses = find+1;

        if(positive_buses + negative_buses > total_buses_negative) total_buses_negative = positive_buses + negative_buses;
        
    }

    ll total_buses_positive = 0;
    for(int i = 0; i < positives.size(); i++){

        if(positives[i] > t) break;

        ll remaining_seconds = t - 2*positives[i];

        ll positive_buses = i+1;
        
        ll find = upper_bound(negatives.begin(), negatives.end(), remaining_seconds) - negatives.begin() -1;

        ll negative_buses = find+1;

        if(negative_buses + positive_buses > total_buses_positive) total_buses_positive = positive_buses + negative_buses;

    }

    ll total_buses = max(total_buses_positive, total_buses_negative);

    if(has_0) total_buses += 1;
    cout << total_buses;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t= 1;// cin >> t;
    while(t--){
        solve();
    }
}