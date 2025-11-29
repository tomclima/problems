/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a>> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a -1);
    }

    queue<int> queue;
    vector<bool> visited(n, 0);
    vector<int> subtree_size;
    visited[0] = true;

    for(auto v : graph[0]){
        int qtd = 1;
        int root = v;
        visited[v] = true;
        queue.push(v);
        while(!queue.empty()){
            int u = queue.front(); queue.pop();
            
            for(auto i : graph[u]){
                if(!visited[i]){
                    qtd++;
                    visited[i] = true;
                    queue.push(i);
                }
            }
        }

        subtree_size.push_back(qtd);
    }

    sort(subtree_size.begin(), subtree_size.end());
    ll sum = 1;
    for(auto val : subtree_size){
        sum += val;
    }
    sum -= subtree_size.back();
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