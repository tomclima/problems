#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

vector<int> visited;
vector<int> parent;
vector<vector<int>> redundant;
vector<pair<int, int>> closed;
vector<pair<int, int>> constructed;

void check_redundancy(int v, int u){
    if(!visited[u]) return;
    if(u != parent[v] and v != parent[u] and redundant[u][v] == false) {
        redundant[v][u] = true;
        closed.push_back(make_pair(v, u));
    }
}

void dfs(vector<vector<int>> &graph, int v){
    visited[v] = true;
    for(int i = 0; i < graph[v].size(); i++){
        check_redundancy(v, graph[v][i]);
        if(visited[graph[v][i]] == false){
            parent[graph[v][i]] = v;
            dfs(graph, graph[v][i]);
        }
    }
}

int next_unvisited(){
    for(int j = 0; j < visited.size(); j++){
        if(visited[j] == 0){
            if(j-1 >= 0 and visited[j-1]){
                constructed.push_back(make_pair(j, j-1));
            }
            return j;
        }
    }
    return -1;
}   


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> graph;
    graph.resize(n);
    visited.resize(n);
    parent.resize(n);
    redundant.resize(n);
    for(int i = 0; i < n; i++){
        redundant[i].resize(n);
    }
    for(int i = 0; i < n-1; i++){
        int v, u;
        cin >> v >> u;
        graph[v-1].push_back(u-1);
        graph[u-1].push_back(v-1);
    }

    int isles = 0;
    int i = 0;
    while(i >= 0){
        dfs(graph, i);
        i = next_unvisited();
        isles++;
    }

    cout << isles -1 << endl;;
    for(int i = 0; i < isles-1; i++){
        cout << closed[i].first+1 << " " << closed[i].second + 1 << " ";
        cout << constructed[i].first + 1 << " " << constructed[i].second + 1 << endl;
    }
}