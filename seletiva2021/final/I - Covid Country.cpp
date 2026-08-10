/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int q, n; cin >> q >> n;

    map<int, ll> cases_by_city;
    multiset<ll> n_cases;
    while (q--){
        int query_type; cin >> query_type;

        if(query_type == 1){
            
            int id; cin >> id;
            ll x; cin >> x;

            if (n_cases.find(cases_by_city[id]) != n_cases.end()){
                n_cases.erase(n_cases.find(cases_by_city[id]));
            }

            cases_by_city[id] += x;
            n_cases.insert(x);
        }

        if(query_type ==2){
            ll k; cin >> k;
            auto end = n_cases.end() - n_cases.upper_bound(k)
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}