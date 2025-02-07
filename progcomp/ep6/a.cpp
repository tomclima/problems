#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lng long long int

vector<vector<lng>> adj;
vector<vector<lng>> capacity;

bool dfs(lng v, lng sink, vector<lng>& parent, vector<bool>& visited) {
    if (v == sink) {
        return true;
    }  
    visited[v] = true;

    for (lng u : adj[v]) {
        if (!visited[u] && capacity[v][u] > 0) { 
            parent[u] = v;
            if (dfs(u, sink, parent, visited)) {
                return true;
            }
        }
    }
    return false;
}

lng maxflow(lng source, lng sink, lng nodes) {
    lng flow = 0;
    vector<lng> parent(nodes);
    vector<bool> visited(nodes);

    while (true) {
        fill(parent.begin(), parent.end(), -1);
        fill(visited.begin(), visited.end(), false);

        if (!dfs(source, sink, parent, visited)) {
            break;
        }

        lng cap = INT_MAX;
        for (lng v = sink; v != source; v = parent[v]) {
            lng u = parent[v];
            cap = min(cap, capacity[u][v]);
        }

        for (lng v = sink; v != source; v = parent[v]) {
            lng u = parent[v];
            capacity[u][v] -= cap;
            capacity[v][u] += cap;
        }

        flow += cap;
    }
    return flow;
}

int main() {
    lng n, m, k;
    cin >> n >> m >> k;
    lng source = 0, sink = n + m + 1;
    lng nodes = sink + 1;

    vector<lng> a;
    a.resize(nodes);
    adj.resize(nodes);
    capacity.resize(nodes);
    for(lng i = 0; i < nodes; i++){
        capacity[i] = a;
    }

    for (lng i = 1; i <= n; i++) {
        adj[source].push_back(i);
        adj[i].push_back(source);
        capacity[source][i] = 1;
    }


    for (lng i = 1; i <= m; i++) {
        adj[n + i].push_back(sink);
        adj[sink].push_back(n + i);
        capacity[n + i][sink] = 1;
    }


    for (lng i = 0; i < k; i++) {
        lng a, b;
        cin >> a >> b;
        b += n;  
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] = 1;
    }


    lng maxPairs = maxflow(source, sink, nodes);
    cout << maxPairs << endl;


    for (lng i = 1; i <= n; i++) {
        for (lng j : adj[i]) {
            if (j > n && j <= n + m && capacity[j][i] == 1) { 
                cout << i << " " << j - n << endl;
            }
        }
    }

    return 0;
}
