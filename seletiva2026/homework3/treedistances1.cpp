/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int


int dfs(vector<vector<int>> &graph, int root, vector<int> &distances){
    vector<int> visited(graph.size());
    stack<int> queue;
    queue.push(root);
    distances[root] = 0;
    int furthest_node = root;
    while(!queue.empty()){
        
        int u = queue.top();
        visited[u] = true;
        queue.pop();
        for(int i : graph[u]){
            
            if(visited[i] == 0){
                distances[i] = 1+distances[u];
                if(distances[i] > distances[furthest_node]) furthest_node = i;
                queue.push(i);
            }
        }
    }

    return furthest_node;
}

int solve(){
    int n; cin >> n;
    vector<vector<int>> tree(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        tree[a -1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }

    vector<int> init_distances(n, -1);
    int edge1 = dfs(tree, 0, init_distances);
    vector<int> distances_edge1(n, -1);
    int edge2 = dfs(tree, edge1, distances_edge1);
    vector<int> distances_edge2(n, -1);
    dfs(tree, edge2, distances_edge2);

    for(int i = 0; i < n; i++){
        cout << max(distances_edge1[i], distances_edge2[i]) << " ";
    }

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