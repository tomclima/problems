/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


ll MOD = static_cast<ll>(1e9+7);

ll mod_mult(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD; 
}


ll int_fastexp(ll val, int pow){
    ll prod = 1; // caso pow == 0
    
    ll pot = val; // caso pow == 1;
    for(ll bit = 0; (1LL << bit) <= pow; bit++){ // iteramos por cada bit da representação binária de pow
        if(pow & (1LL << bit)){ // se aquele bit estiver aceso
            prod = mod_mult(pot, prod);
        }
        pot = mod_mult(pot, pot);
    }
    
    return prod;
}

int solve(){
    int n, m; cin >> n >> m;

    // barra estrela. temos m estrelas e n-1 barras
    ll fact_n = 1;
    for(int i = 1; i <= n-1; i++){
        fact_n = mod_mult(fact_n, i);
    }
    ll fact_m = 1;
    for(int i = 1; i <= m; i++){
        fact_m = mod_mult(fact_m, i);
    }

    ll fact_total = 1;
    for(int i = 1; i < m + n -1; i++){
        fact_total = mod_mult(fact_total, i);
    }


    ll modular_inverse = int_fastexp(mod_mult(fact_m, fact_n), MOD-1);


    cout << mod_mult(fact_total, modular_inverse) << endl;

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