/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


const int LIM = 1e6+5;
vector<bool> isPrime(LIM, true);

vector<int> divisors(LIM, 0);

void sieve_naive(){
    for(int i = 1; i < LIM; i++){
        for(int j = i; j < LIM; j += i){
            divisors[j]++;
        }
    }

    
}


int solve(){

    int x; cin >> x;
    cout << divisors[x] << endl;


    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    sieve_naive();

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}