/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

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

vector<pair<int, int>> prime_decomposition(vector<int> &primes, int n){
    
    if(primes[0] != 2) return {};

    vector<pair<int, int>> decomposition;
    int sum_pow = 0;
    for (int prime : primes){
        if(prime > n) break;
        
        int copy_n = n;
        int pow = 0;
        while(copy_n % prime == 0){
            pow++;
            copy_n /= prime;
        }
        if(pow > 0){
            decomposition.push_back({prime, pow});
            sum_pow += pow;
        }
    }

    return decomposition;
}