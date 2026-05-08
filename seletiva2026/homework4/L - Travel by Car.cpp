/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 400

using Edge = pair<ll, int>;

using RefillNode = pair<ll, pair<ll, int>>; // (refills, (gas, node))

vector<int> djikstra(int src, int max_gas, vector<vector<Edge>> &g){
    
    int n = g.size();
    vector<int> refills(n, MAXN);
    vector<int> curr_gas(n, 0);
    priority_queue<RefillNode, vector<RefillNode>, greater<RefillNode>> queue;

    curr_gas[src] = max_gas;
    refills[src] = 0;
    queue.push(RefillNode({0, {max_gas, src}}));

    while(!queue.empty()){
        
        RefillNode curr = queue.top();
        int v = curr.second.second;
        int gas = curr.second.first;
        int ref = curr.first;


        queue.pop();

        if(ref > refills[v] or (ref == refills[v] and gas < curr_gas[v])){
            continue;
        }

        for(auto [d, w] : g[v]){
            
            if(ref < refills[w] or (ref==refills[w] and gas - d > curr_gas[w])){
                if(d <= gas){
                    refills[w] = ref;
                    curr_gas[w] = gas - d;
                    RefillNode next({ref, {gas - d, w}});
                    queue.push(next);
                }
                else if(d <= max_gas and (ref + 1 < refills[w] or (ref +1 == refills[w] and max_gas -d > curr_gas[w]))){
                    refills[w] = ref+1;
                    curr_gas[w] = max_gas - d;
                    RefillNode next({ref+1, {max_gas -d, w}});
                    queue.push(next);
                }
            }
        }
    }

    return refills;
}

int solve(){
    int n, m; cin >> n >> m;
    ll tank; cin >> tank;


    vector<vector<Edge>> graph(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        ll c; cin >> c;
        graph[a-1].push_back({c, b-1});
        graph[b-1].push_back({c, a-1});
    }


    vector<vector<int>> all_refills;
    for(int i = 0; i < n; i++){
        all_refills.push_back(djikstra(i, tank, graph));
    }

    int q; cin >> q;
    while(q--){
        int src, dst; cin >> src >> dst;
        ll refills = all_refills[src-1][dst-1];

        if (refills >= MAXN) refills = -1;
        cout << refills << endl;
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}