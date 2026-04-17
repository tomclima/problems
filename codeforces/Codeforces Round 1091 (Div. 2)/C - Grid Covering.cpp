/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

// ok fodase eu admito: eu não sei como a minha solução funciona

int solve(){
    ll n, m, a, b; cin >> n >> m >> a >> b;
    a = a % n;
    b = b % m;

    if(gcd(n, a) > 1 or gcd(m, b) > 1) {
        cout << "NO";
        cout << endl;
        return 0;
    }
    
    if(lcm(n, m)*2 < n*m) cout << "NO" << endl;
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