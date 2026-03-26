/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

ll MOD = 1000000007;

int solve(){
    int n; cin >> n;
    stack<ll> k_for;
    k_for.push(1);
    int curr_k = 1;
    ll total = 0;
    for(int i= 0; i < n; i++){
        string op; cin >> op;
        if(op == "for"){
            int k; cin >> k;
            k_for.push(((k_for.top() % MOD) *(k % MOD)) % MOD);
        }
        else if(op == "calc"){
            int k; cin >> k;
            total = (total + (k*k_for.top()) % MOD) % MOD;
        }
        else{
            k_for.pop();
        }
    }

    cout << total << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}