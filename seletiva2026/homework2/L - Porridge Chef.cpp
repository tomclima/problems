/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<ll, ll>

ll INF = 10000000000;

int solve(){
    int n, q; cin >> n >> q;
    vector<pii> events;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        events.push_back({a, +1});
        events.push_back({b+1, -1});
    }

    sort(events.begin(), events.end());

    vector<pii> prefix;
    prefix.push_back({-1, 0});
    for(int i = 1; i <= events.size(); i++){
        prefix.push_back({events[i-1].first, prefix[i-1].second + events[i-1].second});
    }

    while(q--){
        ll t; cin >> t;
        pii pair = {t, INF};
        auto i = upper_bound(prefix.begin(), prefix.end(), pair) - prefix.begin();
        i--;
        cout << prefix[i].second << endl;


    }

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