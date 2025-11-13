/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int dfs(vector<vector<int>> &graph, vector<int> &visited, vector<int> &parent, stack<int> &queue){
    while(!queue.empty()){
        
        int u = queue.top();
        visited[u] = true;
        queue.pop();
        for(int i : graph[u]){
            
            if(visited[i] == 0){
                parent[i] = u;
                queue.push(i);
            }
            else if(visited[i] and i != parent[u]){
                parent[i] = u;
                return i;
            }
        }
    }

    return -1;
}

int solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    vector<int> visited(n, 0);
    vector<int> parent(n, -1);
    stack<int> queue;  
    int cycle = -1;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            queue.push(i);
            cycle = dfs(graph, visited, parent, queue);
            if (cycle != -1){
                break;
            }
        }
    }

    if(cycle == -1){
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> path;
    int u = cycle;
    path.push_back(u);
    do {
        u = parent[u];
        path.push_back(u);
    } while(u != cycle);

    cout << path.size() << endl;
    while(!path.empty()){
        cout << path.back()+1 << " ";
        path.pop_back();
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