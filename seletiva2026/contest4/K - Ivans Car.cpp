/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 10000000
#define pii pair<int, int>


vector<int> djikstra(int origin, int n, vector<vector<pii>> &graph){

    vector<int> dist(n, MAXN);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[origin] = 0;
    pq.push({0, origin});
    while(!pq.empty()){

        auto [dis, v] = pq.top();
        pq.pop();
        if(dis > dist[v]) continue;
        
        for(auto p : graph[v]){

            auto [w, d] = p;

            if(dist[w] > dist[v] + d) {
                dist[w] = dist[v] + d;
                pq.push({dist[w], w});
            }

        }
    } 

    return dist;
}


int solve(){
    int n, m; cin >> n >> m;
    vector<vector<pii>> g(2*n);
    /*
        first n positions are downhill, last n are uphill
    */
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        g[a-1].push_back({n+(b-1), 1}); // downhill to uphill -> weight 1
        g[(a-1) + n].push_back({(b-1) + n, 0}); //uphill to uphill -> weight 0
        g[b-1].push_back({a-1, 0}); // downhill to downhill -> weight 0
        g[(b-1) + n].push_back({a-1, 1}); // uphill to downhill -> weight 1 
    }
    
    int o, d; cin >> o >> d;

    vector<int> dist = djikstra(o-1, 2*n, g);
    int val1 = min(dist[d-1], dist[d-1+n]);
    
    dist = djikstra(o-1+n, 2*n, g);
    int val2 = min(dist[d-1], dist[d-1+n]);

    cout << min(val1, val2) << endl;


    


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