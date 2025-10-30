/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

// pair.first*prefix(m - pair.second +1)

ll mod = 1e9+7;

int solve(){
    int n, m; cin >> n >> m;

    vector<pair<int, int>> movies;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l >> r;
        movies.push_back({l, r});
    }
    
    auto f = [](auto &a, auto &b){
        return a.first < b.first;
    };

    sort(movies.begin(), movies.end());

    vector<ll> prefix;
    prefix.push_back(0);
    for(int i = 1; i <= n; i++){
        prefix.push_back(((prefix[i-1] + m+ 1 - movies[i-1].second) %mod + mod) %mod);
    }

    ll qtd = 0;
    for(int i = 0; i < n; i++){
        auto index = upper_bound(movies.begin(), movies.end(), make_pair(movies[i].second, 0), f) - movies.begin();
        
        qtd = (qtd + ((movies[i].first%mod)*((prefix.back() - prefix[index]) % mod + mod) % mod)%mod)%mod; 
    }

    cout << qtd << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }
}