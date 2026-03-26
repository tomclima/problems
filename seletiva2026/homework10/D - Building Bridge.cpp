/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<ll, ll>

long double dist(pii p1, pii p2){
    long double dx = p1.first - p2.first;
    long double dy = p1.second - p2.second;
    return sqrt(dx*dx + dy*dy);
}

long double get_target_height(pii p, int a){
    return a*(long double)p.second/(long double)p.first;
}

int solve(){
    int n, m, a , b; cin >> n >> m >> a >> b;
    vector<ll> west(n), east(m), east_len(m);
    for (int i = 0; i < n; i++) cin >> west[i];
    for (int i = 0; i < m; i++) cin >> east[i];
    for(int i = 0; i < m; i++) cin >> east_len[i];

    long double best_len = (long double)100000000000;
    int best_east = -1;
    int best_west = -1;

    for(int i = 0; i < m; i++){
        long double target_db = get_target_height({b, east[i]}, a);
        
        int bound = (lower_bound(west.begin(), west.end(), target_db) - west.begin());
        if(bound >= west.size()) bound--;

        long double candidate = dist({b, east[i]}, {a, west[bound]}) + dist({a, west[bound]}, {0, 0});
        int west_cand = bound;
        if(bound > 0){
            long double candidate2 = dist({b, east[i]}, {a, west[bound-1]}) + dist({a, west[bound-1]}, {0, 0});
            if(candidate2 < candidate) {
                candidate = candidate2;
                west_cand = bound-1;
            }
        }

        if(east_len[i] + candidate < best_len) {
            best_len = east_len[i] + candidate;
            best_east = i;
            best_west = west_cand;
        }
    }

    cout << best_west+1 << " " << best_east+1;


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