
#define MAXN 100000000000
#include <bits/stdc++.h>
using namespace std;

int pai[MAXN], sz[MAXN];

int find(int u){
    if(pai[u] == u) return u;
    
    return pai[u] = find(pai[u]);
}

int join(int u, int v){
    u = find(u);
    v = find(v);

    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    pai[v] = u;
    sz[u] += sz[v];
}


int init(){
    for(int u = 0; u < MAXN; u++){
        pai[u] = u;
    }
}
