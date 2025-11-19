/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int remove_one(vector<vector<int>> &graph, vector<int> &deg, vector<int> &visited, int n){
    int max_deg = -1;
    for(int i = 0; i <n; i++){
        if(deg[i] > max_deg) max_deg = deg[i];
    }
    
    vector<int> candidate_vertices;
    for(int i = 0; i < n; i++){
        if(deg[i] == max_deg and !visited[i]) candidate_vertices.push_back(i);
    }
    
    int min_candidates_cut = 1e9;
    int index_chosen = -1;
    for(int u : candidate_vertices){
        int candidates_cut = 0;
        for(int i : graph[u]){  
            if (deg[i] == max_deg) candidates_cut++;
        }
        if(min_candidates_cut > candidates_cut){
            min_candidates_cut = candidates_cut;
            index_chosen = u;
        }
    }
    
    for (auto i : graph[index_chosen]){
        deg[i]--;
    }
    
    visited[index_chosen] = 1;
    int deg_chosen = deg[index_chosen];
    deg[index_chosen] = -1;
    
    return deg_chosen;
}

int solve(){
    int n; cin >> n;
    vector<vector<int>> graph(n);
    vector<int> deg(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
        deg[a-1]++;
        deg[b-1]++;
    }

    vector<int> visited(n);
    
    
    int num_trees = remove_one(graph, deg, visited, n);
    num_trees += remove_one(graph, deg, visited, n) - 1;

    cout << num_trees << endl;
    
    
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