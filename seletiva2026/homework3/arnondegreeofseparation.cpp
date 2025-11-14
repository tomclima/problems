/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int bfs(vector<vector<int>> &graph, int root){
    queue<int> queue;
    vector<int> distance(graph.size(), -1);
    queue.push(root);
    distance[root] = 0;
    int max_distance = 0;

    while(!queue.empty()){
        int u = queue.front(); queue.pop();
        for(int i : graph[u]){
            if(distance[i] == -1){
                queue.push(i);
                
                distance[i] = distance[u] +1;
                if(distance[i] > max_distance) max_distance = distance[i];
            }
        }
    }

    for(int i = 0; i < graph.size(); i++){
        if (distance[i] == -1){
            return -1;
        }
    }

    return max_distance;
}


int solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }


    int max_distance = 0;
    bool possible = true;
    for(int i = 0; i < n and possible; i++){
        int new_distance = bfs(graph, i);
        if(new_distance == -1){
            possible = false;
            break;
        }
        max_distance = max(max_distance, new_distance);

    }

    if(!possible) {
        cout << "=[";
        return 0;
    }

    cout << "=]" << " " << max_distance;

    

    
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