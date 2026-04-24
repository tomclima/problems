/*link*/
 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
 
int solve(){
    int n, m; cin >> n >> m;
    vector<ll> balances(n, 0);
    for(int i = 0; i < m; i++){
        ll from, to, qtd; cin >> from >> to >> qtd;
        balances[from-1] -= qtd;
        balances[to-1] += qtd;
    }
    
    vector<int> devedores;
    vector<int> cobradores;
    for(int i = 0; i < n; i++){
        if(balances[i] > 0) devedores.push_back(i);
        else if(balances[i] < 0 ) cobradores.push_back(i);
    }
 
    if(devedores.size() == 0 and cobradores.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
 
    cout << cobradores.size() + devedores.size() -1 << endl;
    ll total_sum = 0;
    for(auto d : devedores){
        cout << d+1 << " " << *cobradores.begin() +1 << " " <<  balances[d] << endl;
        total_sum += balances[d];
    }
    for(int i = 0; i < cobradores.size() -1; i++){
        cout << cobradores[i]+1 << " " << cobradores[i+1] +1 << " " <<  total_sum + balances[cobradores[i]] << endl;
        total_sum += balances[cobradores[i]];
    }
    
    return 0;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;  //cin >> t;
    while(t--){
        solve();
    }
}