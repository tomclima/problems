/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    int n, m; cin >> n>> m;
    vector<pair<int, int>> roads;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if(a < b){
            roads.push_back({a-1, b-1});
        }
        else{
            roads.push_back({b-1, a-1});
        }
    }

    vector<vector<bool>> inside_blocks(n, vector<bool> (n, false));
    vector<vector<bool>> outside_blocks(n, vector<bool> (n, false));

    string ans;
    bool possible = true;
    for(pair<int, int> road : roads){
        int a = road.first;
        int b = road.second;
        
        // check if inside possible
        if(!inside_blocks[a][b]){
            ans.push_back('i');
            for(int i = a + 1; i < b; i++){
                for(int j = 0; j < n; j++){
                    if(!(j >= a and j <= b)){
                        inside_blocks[i][j] = true;
                        inside_blocks[j][i] = true;
                    }
                }
            }
        }
        else if(!outside_blocks[a][b]){
            ans.push_back('o');
            for(int i = a + 1; i < b; i++){
                for(int j = 0; j < n; j++){
                    if(!(j >= a and j <= b)){
                        outside_blocks[i][j] = true;
                        outside_blocks[j][i] = true;
                    }
                }
            }
        }
        else{
            possible = false;
            break;
        }
    }

    if(!possible) cout << "Impossible";
    else cout << ans;

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