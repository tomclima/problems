/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n, k; cin >> n >> k;
    string corridor; cin >> corridor;
    vector<pair<int, int>> stone_pos_ttm;
    for(int i = 0; i < n; i++){
        if(corridor[i] == 'o'){
            stone_pos_ttm.push_back({i, i - stone_pos_ttm.size() -1});
        }
    }
    
    pair<int, int> stone_last_moved = {0, 0};
    int moved_stones = 0;
    for(auto stone : stone_pos_ttm){
        if(stone.second > k) break;
        moved_stones++;
        stone_last_moved = stone;
    }

    int stone_last_movement = k - stone_last_moved.second;
    
    string suffix = corridor.substr(min(stone_last_moved.first + stone_last_movement +1, n-1));
    string middle = "#";
    for(int i = 0; i < moved_stones; i++){
        middle += "o";
    }

    string prefix;
    for(int i = 0; i < n - (suffix.length() +middle.length()); i++){
        prefix += ".";
    }

    string ans = prefix + middle + suffix;
    cout << ans;




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