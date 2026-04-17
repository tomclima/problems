/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    ll n, m, a, b; cin >> n >> m >> a >> b;
    if(gcd(n, a) > 1 or gcd(m, b) > 1) {
        cout << "NO";
        cout << endl;
        return 0;
    }


    ll i_delta = (a*(b*m)) % n;
    ll j_delta = (b*a*n) %m;
    if(gcd(j_delta, m) > 1 or gcd(i_delta, n) > 1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}