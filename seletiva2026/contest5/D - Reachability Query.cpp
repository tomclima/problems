/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 300000




int pai[MAXN], sz[MAXN], color[MAXN], qtd_black[MAXN];

int find(int u){
    if(pai[u] == u) return u;
    
    return pai[u] = find(pai[u]);
}

void join(int u, int v){
    u = find(u);
    v = find(v);

    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    pai[v] = u;
    sz[u] += sz[v];
    qtd_black[u] += qtd_black[v];
}

int get_black(int u){
    u = find(u);
    return qtd_black[u];
}

void add_black(int u){
    u = find(u);
    qtd_black[u]++;
}

void remove_black(int u){
    u = find(u);
    qtd_black[u]--;
}

void init_dsu(){
    for(int u = 0; u < MAXN; u++){
        pai[u] = u;
        sz[u] = 1;
        color[u] = 0;
        qtd_black[u] = 0;
    }
}


int solve(){
    int n; cin >> n;
    int q; cin >> q;

    for(int i = 0; i < q; i++){
        int query; cin >> query;
        if(query == 1){
            int a, b; cin >> a >> b;
            join(a-1, b-1);
        }
        if(query == 2){
            int v; cin >> v;
            color[v-1] = !color[v-1];
            if(color[v-1]){
                add_black(v-1);
            }
            else{
                remove_black(v-1);
            }
        }
        if(query == 3){
            int v; cin >> v;
            if(get_black(v-1) > 0) cout << "Yes" << endl;
            else cout << "No"   << endl;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    init_dsu();

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}