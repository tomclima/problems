/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000



vector<ll> get_divisors_naive(ll n){
    vector<ll> divisors;
    ll limit = floor(sqrt(n) + 1);
    for(ll i = 1; i < limit; i++){
        if(n % i == 0) {
            divisors.push_back(i);
            if(i != n/i) divisors.push_back(n/i); 
        }
    }

    sort(divisors.begin(), divisors.end());

    return divisors;
}

int solve(){

    ll n; cin >> n;


    vector<ll> divisors = get_divisors_naive(n);

    divisors.pop_back();

    cout << divisors.back() << " "<<  n - divisors.back() <<  endl;    

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