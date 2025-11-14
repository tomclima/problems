/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    int n; cin >> n;
    vector<vector<int>> graph(n);
    vector<int> deg(n);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
        deg[a-1]++;
        deg[b-1]++;
    }


    int no_trees = 1;

    int max_deg = 0;   
    int i_deg = -1;

    for(int i = 0; i < n; i++){
        if(deg[i] > max_deg) {
            max_deg = deg[i];
            i_deg = i;
        }
    }

    no_trees = no_trees -1 + max_deg;
    for(int k : graph[i_deg]){
        deg[k]--;
    }
    deg[i_deg] = -1;

    max_deg = 0;   
    i_deg = -1;

    for(int i = 0; i < n; i++){
        if(deg[i] > max_deg) {
            max_deg = deg[i];
            i_deg = i;
        }
    }

    no_trees = no_trees -1 + max_deg;

    cout << no_trees << endl;



    
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