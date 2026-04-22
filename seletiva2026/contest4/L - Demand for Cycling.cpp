/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){

    ll n; cin >> n;
    ll left = 10000000000;
    ll right = 0;
    ll up = 0;
    ll down = left;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        if(a > right) right = a;
        if(a < left) left = a;
        if(b > up) up = b;
        if(b < down) down = b;
    }

    cout << 4 << endl;
    cout << right << " " << up << endl;
    cout << left << " " <<  up << endl;
    cout << left << " " << down << endl;
    cout << right << " " << down << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
}