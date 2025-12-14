#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


ll MOD = static_cast<ll>(1e9+7);

ll mod_sum(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD; 
}

ll mod_mult(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD; 
}

ll mod_sub(ll a, ll b){
    ll sub = ((a % MOD) - (b % MOD)) % MOD; 
    return (MOD + (sub % MOD)) % MOD;
}
