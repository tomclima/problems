/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 2000000

vector<int> pai(MAXN);

int find(int u){
    if (pai[u] == u) return u;
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    if(u > v){
        int a = u;
        u = v;
        v= a;
    }
    pai[u] = v;
}

void init_dsu(){
    for(int i = 0; i < MAXN; i++){
        pai[i] = i;
    }
}

using Edge = pair<int, int>;

int solve(){
    int n, m; cin >> n >> m;

    vector<Edge> edges;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        edges.push_back({a-1, b-1});
    }

    for(auto [u, v] : edges){
        join(u, v);
    }

    int max = 0;
    int conn = 0;
    for(int i = 0; i < n; i++){

        if(i < max and find(i) != max){
            conn++;
            join(find(i), max);
        }
        if(find(i) > max) max = find(i);
    }
    
    cout << conn << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    init_dsu();
    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}