#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    // crivo de erastotenes
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime [1] = false;
    for(int i = 2; i * i <= n; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= n; j+= i){
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    int last_prime = 2;
    for(int i = 3; i <= n; i++){
        if(isPrime[i] and isPrime[i + last_prime + 1]){
            if(i + last_prime + 1 > n or count >= k) break;
            else count++;
            last_prime = i;
        }
        else if(isPrime[i]){
            last_prime = i;
        }
    }

    if(count >= k){
        cout << "YES";
    }
    else{
        cout << "NO";
    }



}