/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int

bool check(ll x){
    cout << "? " << x << endl;
    string resp; cin >> resp;

    if(resp == "NO") return 1;
    else{
        return 0;
    }
}


int solve(){

    ll l = 0;
    ll r = 1e9;
    while (l <= r){
        ll middle = l + (r - l)/2;
        if (check(middle)){
            r = middle-1;
        }
        else{
            l = middle+1;
        }
    }

    cout << "! " << l << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;// cin >> t;
    while(t--){
        solve();
    }
}