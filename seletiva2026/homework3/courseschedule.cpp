/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int


int solve(){
    ll n; cin >> n;
    ll m; cin >> m;

    vector<int> degree(n, 0);
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        degree[b-1]++;
    }

    // toposort
    queue<int> topo_queue;
    for(int i = 0; i < n; i++){
        if(degree[i] ==0) topo_queue.push(i);
    }

    vector<int> ord;
    while(!topo_queue.empty()){
        int u = topo_queue.front(); topo_queue.pop();
        ord.push_back(u);
        for(int v: graph[u]){
            degree[v]--;
            if(degree[v] == 0) topo_queue.push(v);
        }
    }

    if(ord.empty() or ord.size() < n) cout << "IMPOSSIBLE" << endl;
    else{
        for(int i = 0; i < n; i++){
            cout << ord[i]+1 << " ";
        }
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