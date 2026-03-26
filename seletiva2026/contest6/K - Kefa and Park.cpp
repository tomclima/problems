/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<int, int>


int solve(){
    int n, m; cin >> n >> m;
    vector<int> cat(n);
    for(auto &i : cat) cin >> i;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[b-1].push_back(a-1);
        graph[a-1].push_back(b-1);
    }

    vector<bool> visited(n);
    visited[0] = true;
    stack<pii> q;
    int restaurants = 0;
    q.push({0, m-cat[0]});
    while(!q.empty()){
        auto [v, cats] = q.top();
        q.pop();
        if(cats < 0) continue;
        if (v != 0 and graph[v].size() == 1) restaurants++;
        for(auto w : graph[v]){
            if (!visited[w]){
                visited[w] = true;
                int w_c;
                if(cat[w]) w_c = cats-1;
                else{
                    w_c = m;
                } 
                q.push({w, w_c});
            }
        }
    }

    cout << restaurants << endl;



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