#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int



vector<int> holes;
int dfs(vector<int> &graph, int v){
    if(holes[graph[v]] > 0){
        fill(holes.begin(), holes.end(), 0);
        return graph[v];
    }
    holes[v]++;
    return dfs(graph, graph[v]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<int> graph;
    int n;
    cin >> n;
    graph.resize(n);
    holes.resize(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x; 
        graph[i] = x-1;
    }

    for(int i = 0; i < n; i++){
        int x = dfs(graph, i);
        cout << x+1 << " ";
    }
}