/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

vector<int> color(2*1e5, -1);

pair<int, int> dfs(vector<vector<int>> &graph, vector<int> &visited, vector<ll> &island_sizes, vector<int> &island_connections, int root, int island){
    ll white = 0;
    ll black = 0;
    stack<int> queue;
    color[root] = 0;
    queue.push(root);

    int connections = 0;
    while(!queue.empty()){
        
        int u = queue.top(); queue.pop();
        island_sizes[island]++;
        connections += graph[u].size(); 

        if(color[u] == 0) white++;
        else black++;

        for(int i : graph[u]){
            if(!visited[i]){
                visited[i] = true;
                color[i] = !color[u];
                queue.push(i);
            }
            else if(color[i] == color[u]) return {0, 0};
        }
    }

    island_connections[island] = connections/2;
    return {white, black};
}


int solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >>a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    vector<ll> island_sizes(n, 0);
    vector<int> island_connections(n, 0);
    vector<pair<ll, ll>> bipartite_island(n);
    vector<int> visited(n, 0);
    int island_number = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            visited[i] = true;
            bipartite_island[island_number] = dfs(graph, visited, island_sizes, island_connections, i, island_number);
            island_number++;
        }
    }

    // check if graph is already bipartite. All components are bipartite
    bool all_bipartite = true;
    for(int i = 0; i < island_number; i++){
        all_bipartite &= (bipartite_island[i] != make_pair((ll)0, (ll)0));
    }

    if(!all_bipartite){
        cout << "0" << endl;
        return 0;
    }
    

    ll sum = 0;
    ll all_prod = 1;
    ll sizes_sum = 0;
    // calculate the number of internal connection possibilities
    for(int i = 0; i < island_number; i++){
        sum += bipartite_island[i].first*bipartite_island[i].second - island_connections[i];
        sizes_sum += island_sizes[i]; 
    }

    
    // calculate the combinations
    ll combinations = 0;
    for(int i = 0; i < island_number; i++){
        sizes_sum -= island_sizes[i];
        combinations += island_sizes[i]*sizes_sum;
        sizes_sum += island_sizes[i];
    }

    sum += combinations/2;

    cout << sum << endl;
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