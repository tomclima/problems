/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll least = 1e18;
        map<ll, int> freqs;
        for(int i = 0; i < n; i++){
            ll val; cin >> val;
            if(val < least) least = val;
            freqs[val]++;
        }

        cout << n - freqs[least] << endl;
    }
}