/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 10000000000001


const int LIM = 1e7+5;
vector<bool> isPrime(LIM, true);

vector<int> divisors(LIM, 0);

void sieve_naive(){
    divisors[1] = 1;
    for(int i = 2; i < LIM; i++){
        for(int j = i; j < LIM; j += i){
            divisors[j]++;
        }
    }

    
}

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


int solve(vector<int> &primes){
    ll n; cin >> n;
    
    ll nextprime = -1;
    for(int i = n+1; i < MAXN+1; i++){
        
        bool i_is_prime = true;

        if(i < LIM){
            i_is_prime = isPrime[i];
            if(i_is_prime){
                nextprime = i;
                break;
            }
        }


        for(int j = 0; j < sqrt(i)+1; j++){
            if(i % primes[j] == 0){
                i_is_prime = false;
            }
        }


    }

    cout << prime;
    
    
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> primes = sieve_optimal();
    int t = 1; cin >> t;
    while(t--){
        solve(primes);
    }
}