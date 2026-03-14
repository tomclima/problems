/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int get_flips(ll init, ll limit){
    int i = 1;
    ll k = init;
    while(k < limit){
        i *= 2;
        k *= 2;
    }
    return i;
}

int solve(){
    ll n, k; cin >> n >> k;
    long double sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (long double)(((long double)1/n) * (long double)((long double)1/(get_flips(i, k))));
    }
    cout << fixed << setprecision(19) << sum;
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