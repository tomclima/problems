/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 2*100000*1000000000

bool check(){
    
}

int solve(){

        // closed interval [lo, hi]
    ll l = 0;
    ll r = 1e18;
    while (l <= r){
        ll middle = l + (r - l)/2;
        if (check()){
            r = middle-1;
        }
        else{
            l = middle+1;
        }
    }
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