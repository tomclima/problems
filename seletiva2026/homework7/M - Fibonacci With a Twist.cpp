/*a*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


ll MOD = static_cast<ll>(1e9+7);

ll mod_mult(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD; 
}

ll mod_sum(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD; 
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


ll vec_dot(vector<ll> v1, vector<ll> v2){
    ll dot = 0;
    for(int i = 0; i < v1.size(); i++){
        dot = mod_sum(dot, mod_mult(v1[i], v2[i]));
    }

    return dot;
}



vector<vector<ll>> matrix_mult(vector<vector<ll>> &mat1, vector<vector<ll>> &mat2){

    vector<vector<ll>> ret(mat1.size(), vector<ll>(mat2[0].size()));

    vector<vector<ll>> transpose(mat2[0].size(), vector<ll>(mat2.size()));
    for(int i = 0; i < mat2.size(); i++){
        for(int j = 0; j < mat2[0].size(); j++){
            transpose[j][i] = mat2[i][j];
        }
    }

    for(int i = 0; i < mat1.size(); i++){
        for(int j = 0; j < mat2[0].size(); j++){
            ret[i][j] = vec_dot(vector<ll>(mat1[i].begin(), mat1[i].end()), transpose[j]);
        }
    }

    return ret;
}

vector<vector<ll>> matrix_fastexp(vector<vector<ll>> &mat, ll pow){
    // initialize prod to be the identity vector
    vector<vector<ll>> prod(mat.size(), vector<ll>(mat.size()));
    for(int i = 0; i < mat.size(); i++){
        prod[i][i] = 1;
    }

    vector<vector<ll>> pot = mat;
    for(ll bit = 0; (1LL << bit) <= pow; bit++){ // iteramos por cada bit da representação binária de pow
        if(pow & (1LL << bit)){ // se aquele bit estiver aceso
            prod = matrix_mult(pot, prod);
        }
        pot = matrix_mult(pot, pot);
    }
    
    
    return prod;
}

/*

ft(n) = ft(n-1) + ft(n-2) + n - 1

(ft(n-1) + ft(n-2) + n -1, ft(n-1), n, 1) 
=

1  1  1  0
1  0  0  0 
0  0  1  1
0  0  0  1
*
(ft(n-1), ft(n-2), n-1, 1) 

*/
int solve(vector<vector<ll>> &transform){
    int n; cin >> n >> MOD;
    
    

    vector<ll> initial_state = {2, 1, 2, 1};
    vector<vector<ll>> exp = matrix_fastexp(transform, max(n-2, 0));
    ll fib_t = vec_dot(exp[0], initial_state);
    if(n == 0) fib_t = 0;
    if(n == 1) fib_t = 1;

    cout << fib_t << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<ll>> transform = {
        {1, 1, 1, 0},
        {1, 0, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    int t = 1; cin >> t;
    while(t--){
        solve(transform);
    }
}