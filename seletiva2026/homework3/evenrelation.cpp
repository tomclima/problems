/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int


int solve(){
    int n; cin >> n;
    vector<map<int, int>> weights(n);
    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1; i++){
        int a, b , c; cin >> a >> b >> c;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
        weights[a-1][b-1] = c;
        weights[b-1][a-1] = c;
    }

    vector<int> distances(n, -1);
    stack<int> queue;
    queue.push(0);
    distances[0] = 0;
    while(!queue.empty()){
        int u = queue.top(); queue.pop();
        for(int i : graph[u]){
            if(distances[i] == -1){
                distances[i] = distances[u] + weights[u][i];
                queue.push(i);
            }
        }
    }
    
    vector<int> colors(n, -1);
    colors[0] = 0;
    for(int i = 1; i < n; i++){
        if(distances[i]%2 != distances[0]%2) colors[i] = 1;
    }

    for(int i = 0; i < n; i++){
        if(colors[i] == -1) colors[i] = 0;
    }

    for(int i = 0; i < n; i++){
        cout << colors[i] << endl;
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