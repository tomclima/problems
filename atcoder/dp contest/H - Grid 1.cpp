/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

ll mod = (ll)1000000000+(ll)7;

ll backtrack(int w, int h, vector<vector<ll>> &grid){
    if(grid[h][w] != -1) return grid[h][w];
    else{
        return grid[h][w] = (backtrack(w-1, h, grid) % mod + backtrack(w, h-1, grid)%mod) % mod; 
    }
}

int solve(){
    int h, w ; cin >> h >> w;
    vector<vector<ll>> grid(h, (vector<ll>(w, -1)));
    vector<string> lines;

    for(int i = 0; i < h; i++){
        string line; cin >> line;
        lines.push_back(line);
        for(int j = 0; j < w; j++){
            if(line[j] == '#'){
                grid[i][j] = 0;
            }
        }
    }

    bool found = false;
    for(int i = 0; i < w; i++){
        found |= lines[0][i] == '#';
        grid[0][i] = 1 - found;
    }
    found = false;
    for(int j = 0; j < h; j++){
        found |= lines[j][0] == '#';
        grid[j][0] =1 - found;
    }

    cout << backtrack(w-1, h-1, grid) << endl;
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