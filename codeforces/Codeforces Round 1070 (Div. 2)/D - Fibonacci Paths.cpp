/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


int solve(){
    int n, m; cin >> n >> m;
    vector<ll> vertices(n);
    vector<vector<int>> graph(n);
    for(ll  &i : vertices) {
        cin >> i;
    }
    for(int i = 0; i < m; i++){
        int a, b; cin >> a>> b;
        graph[a-1].push_back(b-1);
    }


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