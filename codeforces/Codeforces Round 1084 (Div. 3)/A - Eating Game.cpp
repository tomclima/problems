/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n;cin >> n;
    vector<int> table(n);
    for(auto &i : table) cin >> i;
    int total_dishes = 0;
    for(int i = 0; i < n; i++){
        total_dishes += table[i];
    }

    set<int> winners;
    for(int i = 0; i < n; i++){
        int curr_player = i;
        vector<int> copy = table;
        copy[curr_player]--;
        int copy_dishes = total_dishes;
        copy_dishes--;
        while(copy_dishes > 0){
            curr_player = (curr_player + 1) % n;
            if(copy[curr_player] > 0){
                copy[curr_player]--;
                copy_dishes--;
            }
        }
        winners.insert(curr_player);
    }

    cout << winners.size() << endl;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}