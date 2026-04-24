/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    vector<pair<ll, ll>> a;
    for(int i = 0; i < n; i++){
        ll start, finish; cin >> start >> finish;
        a.push_back({finish, start});
    }
    sort(a.begin(), a.end());
    ll curr = a[0].first;
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(a[i].second >= curr){
            curr = a[i].first;
            cnt++;
        }
    }

    cout << cnt << endl;
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
}