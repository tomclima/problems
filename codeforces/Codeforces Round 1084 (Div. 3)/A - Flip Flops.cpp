/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    ll n, c, k; cin >> n >> c >> k;
    vector<ll> monsters(n);
    for(auto &i : monsters) cin >> i;
    sort(monsters.begin(), monsters.end());
    
    for(int i = 0; i < n; i++){
        if(monsters[i] < c and k > 0){
            ll diff = c - monsters[i];
            c+= monsters[i] + min(diff, k);
            k-= min(diff, k);

        }
        else if(monsters[i] <= c){
            c+= monsters[i];
        }
        else{
            break;
        }
    }

    cout << c << endl;

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