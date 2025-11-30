/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 200000

int pai[MAXN];

int find(int u){
    if(pai[u] == u) return u;
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    pai[v] = u;
}

void init_dsu(){
    for(int u = 0; u < MAXN; u++){
        pai[u] = u;
    }

}

int qtd_disjoints(int n){
    int qtd = 0;
    vector<bool> visited(n, 0);
    for(int i = 0; i < n; i++){
        if(!visited[find(i)]) {
            visited[find(i)] = true;
            qtd++;
        }
    }

    return qtd;
}


int solve(){
    int n, m; cin >> n >> m;
    vector<tuple<int, int>> edges;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        edges.push_back({a-1, b-1});
    }

    int q; cin >> q;
    vector<bool> to_be_removed(m, 0);
    vector<int> removals;
    for(int i = 0; i < q; i++){
        int index; cin >> index;
        to_be_removed[index -1] = true;
        removals.push_back(index -1);
    }

    reverse(removals.begin(), removals.end());

    for(int i = 0; i < m; i++){
        if(!to_be_removed[i]){
            auto [a, b] = edges[i];
            join(a, b);
        } 
    }

    vector<int> disjoints;
    disjoints.push_back(qtd_disjoints(n));

    for(int i = 0; i < q; i++){
        auto [a, b] = edges[removals[i]];
        if(find(a) != find(b)){
            disjoints.push_back(disjoints.back() - 1);
        }
        else{
            disjoints.push_back(disjoints.back());
        }
        join(a, b);
    }

    disjoints.pop_back();

    reverse(disjoints.begin(), disjoints.end());
    cout << disjoints[0];
    for(int i = 1; i < q; i++){
        cout << " " << disjoints[i];
    }
    cout << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    init_dsu();
    while(t--){
        solve();
    }
}