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

ll mod_sum(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD; 
}


ll int_fastexp(ll val, ll pow){
    ll prod = 1; // caso pow == 0
    
    ll pot = val; // caso pow == 1;
    for(ll bit = 0; (1LL << bit) <= pow; bit++){ // iteramos por cada bit da representação binária de pow
        if(pow & ( 1LL << bit)){ // se aquele bit estiver aceso
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
        if(pow & ( 1LL << bit)){ // se aquele bit estiver aceso
            prod = matrix_mult(pot, prod);
        }
        pot = matrix_mult(pot, pot);
    }
    
    
    return prod;
}

/*
Recorrencia dos coeficientes de a e de b: P(x) = (a, b)
P(x) = (P(x-1).first + P(x-1).second, P(x-1).first + 2P(x-1).second) -> transformação linear!

vetor de estado
(a, b)

matriz de transformação
1 1 
1 2

(a, b)x = (1, 1, 1, 2)^x(a-1, b-1) 
*/


int solve(){
    ll n; cin >> n;
    ll a, b; cin >> a >> b;
    n--;

    
    vector<vector<ll>> mat = {
        {1, 1},
        {1, 2}
    };

    mat = matrix_fastexp(mat, n/2);


    int player = n % 2;
    string name = "Samuell";
    vector<ll> initial_state = {0, 0};
    if( player == 0){
        initial_state = {1, 0};
        name = "Samuell";
    }
    else{
        initial_state = {0, 1};
        name = "Lleumas";
    }

    vector<ll> last_state = {vec_dot(mat[0], initial_state), vec_dot(mat[1], initial_state)};
    cout << name << endl;
    cout << mod_sum(mod_mult(a, last_state[0]), mod_mult(b, last_state[1]));
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