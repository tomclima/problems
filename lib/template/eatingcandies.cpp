/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int

int solve(){

    int n; cin >> n;
    vector<ll> candies;
    for(int i = 0; i < n; i++){
        ll w; cin >> w;
        candies.push_back(w);
    }
    vector<ll> prefix_left(1, 0);
    vector<ll> prefix_right(1, 0);
    for(int i = 1; i<= n; i++){
        prefix_left.push_back(prefix_left[i-1] + candies[i-1]);
    }

    reverse(candies.begin(), candies.end());
    for(int i = 1; i <= n; i++){
        prefix_right.push_back(prefix_right[i-1] + candies[i-1]);
    }

    ll max = 0;
    for(int i = 0; i < prefix_left.size(); i++){
        
        int find = lower_bound(prefix_right.begin(), prefix_right.end(), prefix_left[i]) - prefix_right.begin();
        if(prefix_right[find] != prefix_left[i]) continue;
        if(find > n-i) break;


        if(find + i > max) max = find+i;

    }

    cout << max << endl;

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