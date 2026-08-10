/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000



int solve(){
    
    int n, m; cin >> n >> m;
    vector<string> grid;

    map<char, int> rel;
    rel['A'] = 0;
    rel['B'] = 1;
    rel['C'] = 2;
    rel['D'] = 3;

    string colors = "ABCD";

    for(int i = 0; i < n; i++){
        string line; cin >> line;
        grid.push_back(line);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            vector<bool> disallowed(4);
            disallowed[rel[grid[i][j]]] = 1;
            if(i -1 >= 0) disallowed[rel[grid[i-1][j]]] = 1;
            if(j - 1 >= 0) disallowed[rel[grid[i][j-1]]] = 1;
            for(int k = 0; k < 4; k++){
                if(!disallowed[k]) grid[i][j] = colors[k];
            }
            cout << grid[i][j] << "";
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