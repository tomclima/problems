/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 400
#define pll pair<ll, ll>

ll MAX_DIST = 2000000000;

using Edge = pair<ll, int>;

int solve(){
    int n, m; cin >> n >> m;
    ll tank; cin >> tank;


    vector<vector<ll>> graph(n, vector<ll> (n, MAX_DIST));
    for(int i = 0; i < n; i++){
        graph[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        ll c; cin >> c;
        graph[a-1][b-1]  = c;
        graph[b-1][a-1] = c;
    }
    

    vector<vector<ll>> mindist;
    mindist = graph;

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                mindist[i][j] = min(mindist[i][j], mindist[i][k] + mindist[k][j]);
                mindist[j][i] = mindist[i][j];
            }
        }
    }

    vector<vector<ll>> all_refills(n, vector<ll> (n, MAXN));    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mindist[i][j] <= tank) all_refills[i][j] = 0;
            all_refills[j][i] = all_refills[i][j];
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                all_refills[i][j] = min(all_refills[i][j], all_refills[i][k] + all_refills[k][j] + (mindist[i][j] > tank));
            }
        }
    }
    

    int q; cin >> q;
    while(q--){
        int src, dst; cin >> src >> dst;
        ll refills = all_refills[src-1][dst-1];

        if (refills >= MAXN) refills = -1;
        cout << refills << endl;
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