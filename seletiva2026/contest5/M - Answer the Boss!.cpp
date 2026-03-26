/*link*/

#include <bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

using namespace std;
int get_rank(int n, vector<int> &rank, vector<vector<int>> &relations){
    if(rank[n] != -1) return rank[n];
    
    rank[n] = 1;
    for(auto i : relations[n]){
        rank[n] = max(rank[n], 1 + get_rank(i, rank, relations));
    }

    return rank[n];
}

int solve(){
    int n, m; cin >> n >> m;
    vector<int> rank(n, -1);
    vector<vector<int>> relations(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        relations[a].push_back(b);
    }
    map<int, set<int>> rank_person; 
    set<int> ranks;
    for(int i = 0; i < n; i++) {
        int new_rank = get_rank(i, rank, relations);
        rank_person[new_rank].insert(i);
        ranks.insert(new_rank);
    }
    for(auto i : ranks){
        for (auto j : rank_person[i]){
            cout << i << " " << j << endl;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        cout << "Scenario " << "#" << i+1 << ":" << endl;
        solve();
    }
}