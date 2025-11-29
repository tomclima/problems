/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int n, r;
vector<bool> visited(10000, false);

int get_rank(int u, vector<vector<int>> &graph, vector<int> &dp){
    if(visited[u]) return max(1, dp[u]);
    if(dp[u] != -1) return dp[u];
    visited[u] = true;
    // if(graph[u].size() == 0) return dp[u] = 1;

    int rank = 1;
    for(auto i : graph[u]){
        if(1 + get_rank(i, graph, dp) > rank) rank = 1 + get_rank(i, graph, dp);
    }

    return dp[u] = rank;
}

int solve(){

    cin >> n >> r;
    vector<vector<int>> graph(n);
    vector<int> dp(n, -1);
    for(int i = 0; i < r; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    for(int i = 0; i < n; i++){
        get_rank(i, graph, dp);
    }

    vector<set<int>> ranks(10000);
    int max_rank = 1;
    for(int i = 0; i < n; i++){
        ranks[get_rank(i, graph, dp)].insert(i);
        if(get_rank(i, graph, dp) > max_rank) max_rank = get_rank(i, graph, dp);
    }

    for(int i = 1; i <= max_rank; i++){
        for(auto a : ranks[i]){
            cout << i << " ";
            cout << a << " ";
            cout << endl;
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i = 1;
    int t = 1; cin >> t;
    while(t--){
        cout << "Scenario #"<<i<< ":" << endl;
        solve();
        i++;
    }
}