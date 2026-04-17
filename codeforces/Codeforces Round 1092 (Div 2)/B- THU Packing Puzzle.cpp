/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    ll t, h, u; cin >> t >> h >> u;
    ll sum = 0;
    ll a = min(t, u);
    sum += 4*a;
    t-=a;
    u-=a;
    ll b = min(h, t/2);
    h -= b;
    t-= 2*b;
    sum += 7*b;
    if(h > 0 and t > 0){
        sum += 5;
        t-=1;
        h-=1;
    }
    if(t > 0){
        sum += 3*t - (t-1);

    }
    t = 0;


    sum += (t +u + h)*3;

    cout << sum << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;  cin >> t;
    while(t--){
        solve();
    }
}