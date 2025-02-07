#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

vector<int> visited;
vector<int> parent;
vector<pair<int, int>> redundant;
vector<pair<int, int>> constructed;


void dfs(vector<vector<int>> &graph, int v){
    visited[v] = true;
    for(int i = 0; i < graph[v].size(); i++){
        if(visited[graph[v][i]] and graph[v][i] != parent[v]){
            redundant.push_back(make_pair(v, graph[v][i]));
        }
        else if(visited[graph[v][i]] == 0){
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
        cout << redundant[i].first+1 << " " << redundant[i].second + 1 << " ";
        cout << constructed[i].first + 1 << " " << constructed[i].second + 1 << endl;
    }
}