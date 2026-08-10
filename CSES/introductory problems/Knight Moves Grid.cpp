/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<int, int>

vector<int> dx = {+2, +2, +1, +1, -2, -2, -1, -1};
vector<int> dy = {+1, -1, +2, -2, -1, +1, -2, +2};

ll INF = MAXN;


bool is_valid(int x, int y, int n){
    if(x < 0 or x >= n) return false;
    if(y < 0 or y >=n) return false;
    return true;
}

int solve(){
    int n; cin >> n;

    // bfs instantiation
    vector<vector<ll>> dist(n, vector<ll> (n, INF));
    queue<pii> next;
    
    // origin
    dist[0][0] = 0;
    next.push({0, 0});
    

    while(!next.empty()){
        
        auto [y, x] = next.front();
        next.pop();
        
        for(int i = 0; i < 8; i++){
            int new_y = y +dy[i];
            int new_x = x + dx[i];
            if(is_valid(new_y, new_x, n)){
                if(dist[new_y][new_x] >= INF){
                    dist[new_y][new_x] = dist[y][x] + 1;
                    next.push({new_y, new_x});
                }
            }
        }
    }

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            cout << dist[y][x] << " ";
        }
        cout << endl;
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