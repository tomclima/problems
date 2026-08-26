#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define pii pair<int, int>

using namespace std;


ll factorize(ll n, int factor){

    int i = 0;

    while(n){

        if(n % factor == 0){
            i++;
            n/=factor;
        }

        else{
            break;
        }
    }

    return i;
}

int solve(const vector<int> &primes, map<int, ll> &prime_freq){
    
    int q; cin >> q;

    map<int, ll> mult_penalty;
    for (auto prime : primes){

        mult_penalty[prime] = 0;
    
    }

    ll mult_factor = 1;

    while(q--){
        
        int t, x; cin >> t >> x;

        if (t == 1){

            if(prime_freq.find(x) != prime_freq.end()){

                if(prime_freq[x] == 0) mult_penalty[x] = mult_factor -1;
                
                prime_freq[x] += 1;

                continue;

            }

            for(auto prime : primes){

                if (prime > sqrt(x)) break;

                int fact = factorize(x, prime);

                if(fact > 0 and prime_freq[prime] == 0) mult_penalty[prime] = mult_factor;
                
                prime_freq[prime] += fact;
                
            }
        }

        if(t == 2){

            mult_factor *= x;
        
        }

        if (t ==3){

            bool is_divisor = true;

            // check if x is prime itself
            if(prime_freq.find(x) != prime_freq.end()){

                if(prime_freq[x] > 0){
                    cout << "Yes" << endl;
                }
                else cout << "No" << endl;
                continue;
            }

            // check prime factorization
            for(auto prime : primes){

                if (prime > sqrt(x)) break;

                int fact = factorize(x, prime);

                if (prime_freq[prime] * (mult_factor/mult_penalty[prime]) < fact){

                    is_divisor = false;
                    break;

                }

            }

            if (is_divisor) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    map<int, ll> prime_freq; 
    vector<int> primes;
    for(int i = 2; i <= 100001; i++){
        int is_prime = true;
        for(int j = 2; j < floor(sqrt(i)) + 1 and is_prime; j++){
            if(i % j == 0) is_prime = false;
        } 
        if(is_prime) {
            prime_freq[i] = 0;
            primes.push_back(i);
        }
    }

    int t = 1; //cin >> t;
    while(t--){
        solve(primes, prime_freq);
    }
    return 0;
}