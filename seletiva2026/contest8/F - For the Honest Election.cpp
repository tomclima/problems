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

vector<ll> get_divisors_naive(ll n){
    vector<ll> divisors;
    ll limit = floor(sqrt(n) + 1);
    for(ll i = 1; i < limit; i++){
        if(n % i == 0){
          divisors.push_back(i);  
          if(i != n/i) divisors.push_back(n/i); 
        } 
    }

    sort(divisors.begin(), divisors.end());

    divisors.pop_back();
    return divisors;
}





map<ll, ll> dp;

ll get_dp(ll n){
    
    if(dp.find(n) != dp.end()) return dp[n];
    vector<ll> div = get_divisors_naive(n); 
    
    dp[n] = n/2+1;
    for(auto divisor : div){
        dp[n] = min(dp[n], ((n/divisor)/2 +1) * get_dp(divisor));
    }
    return dp[n];
}

int solve(){
    ll n; cin >> n;
    cout << get_dp(n);
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}