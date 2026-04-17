/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

const int LIM = 1e7+5;
vector<bool> isPrime(LIM, true);


vector<ll> sieve_optimal(){ // get number of primes for the max possible value;
    isPrime[0] = isPrime[1] = false;
    
    vector<ll> primes;
    for(int i = 2; i < LIM; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = i+i; j < LIM; j+=i){
                isPrime[j] = false;
            }
        }
    }

    return primes;
}



int solve(vector<ll> &p){
    int n; cin >> n;
    ll curr_val = p[0];
    int i = 0;
    while(n--){
        i++;
        cout << curr_val << " ";
        curr_val = p[i-1] * p[i];
    }
    cout << endl;

    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<ll> primes = sieve_optimal();
    primes.insert(primes.begin(), 1);

    int t = 1;  cin >> t;
    while(t--){
        solve(primes);
    }
}