/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

ll sum_prog(int n){
    ll a0 = 1;
    ll a1 = 2;
    ll r = 2;
    ll an = a1 + r*(n-2);

    return 1 + (a1 + an)*(n-1)/2;
}

int solve(){
    
    int y, x; cin >> x >> y;
    int n = max(x, y);

    ll diagonal = sum_prog(n);

    
    ll ans = diagonal;

    ll diff = y - x;
    if (n % 2 == 1){
        ans = diagonal + diff;
    }
    else{
        ans = diagonal - diff;
    }

    cout << ans << endl;


    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }

    return 0
}