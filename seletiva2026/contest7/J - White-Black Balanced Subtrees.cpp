/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define BIAS_UNINT 1234567


int get_bias(int node, vector<vector<int>> &tree, string &colors, vector<int> &biases){
    if(biases[node] != BIAS_UNINT) return biases[node];

    int bias = 0;
    if(colors[node] == 'B') bias = 1;
    else bias = -1;

    for(auto i : tree[node]){
        bias += get_bias(i, tree, colors, biases);
    }

    return biases[node] = bias;
}

int solve(){
    int n; cin >> n;
    vector<vector<int>> tree(n);
    vector<int> bias(n, BIAS_UNINT);

    for(int i = 0; i < n-1; i++){
        int v; cin >> v;
        tree[v-1].push_back(i+1);
    }

    string colors;
    cin >> colors;

    get_bias(0, tree, colors, bias);

    int n_balanced = 0;
    for(auto b : bias){
        if(b == 0) n_balanced++;
    }

    cout << n_balanced << endl;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}