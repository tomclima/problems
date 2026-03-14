#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

// fui moggado pela leitura 



const int LIM = 1e7+5;
vector<bool> isPrime(LIM, true);

vector<int> divisors(LIM, 0);

set<int> new_primes;



vector<int> sieve_optimal(){ // get number of primes for the max possible value;
    isPrime[0] = isPrime[1] = false;
    
    vector<int> primes;
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

// checks if we found an already found prime
bool prime_decomposition(vector<int> &primes, int n){
    
    if(primes[0] != 2) return;


    for (int prime : primes){
        if(prime > sqrt(n)+1) break;
        
        if(n % prime == 0){
            if(new_primes.find(prime) != new_primes.end()){
                return true;
            }
            new_primes.insert(prime);
        }
    }

    return false;
}



int solve(){
    for(int i = 0; i < n; i++){

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