/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    ll p, q; cin >> p >> q;
    if(q < p or 3*(q - p) > q or (q - p == 0)) cout << "Alice" << endl;
    else cout << "Bob" << endl;
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