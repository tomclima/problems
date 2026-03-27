/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<ll, ll>

ll INF = 10000000000;

int solve(){
    int n; cin >> n;
    multiset<pii> shows;
    for(int i = 0; i < n; i++){
        ll a, b; cin >> a >> b;
        shows.insert({a, b});
    }

    for(int i = 0; i < 2; i++){
        auto iter = shows.begin();
        while(iter != shows.end()){
            int next = (*iter).second;
            shows.erase(iter);
            iter = shows.upper_bound({next, INF});
        }
    }

    if(!shows.empty()) cout << "NO";
    else cout << "YES";
    cout << endl;


    

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