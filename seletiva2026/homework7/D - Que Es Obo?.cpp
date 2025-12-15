/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000




const int LIM = 2e7+5;
vector<bool> isPrime(LIM, true);

vector<int> sieve(){
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

int solve(vector<int> primes){
    ll a, x_max; cin >> a >> x_max;
    int n;

    vector<pair<int, int>> decomposition;
    int sum_pow = 0;
    for (int prime : primes){
        if(prime > a) break;
        
        int copy_a = a;
        int pow = 0;
        while(copy_a % prime == 0){
            pow++;
            copy_a /= prime;
        }
        if(pow > 0){
            decomposition.push_back({prime, pow});
            sum_pow += pow;
        }
    }

    if(decomposition.back().first > x_max){
        cout << "Que es Obo?";
    }
    else{  
        cout << sum_pow << endl;
    }

    
    return 0;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> primes = sieve();
    int t = 1;
    while(t--){
        solve(primes);
    }
}