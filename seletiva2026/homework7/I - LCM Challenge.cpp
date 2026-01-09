/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    ll n;cin >> n;

    
    if (n == 1) cout << 1;
    else if(n == 2) cout << 2;
    else if (n == 3) cout << 6; 
    else if (n%2 == 0 and n%3 == 0) cout << (n-1)*(n-2)*(n-3);
    else if(n%2 == 0) cout << n*(n-1)*(n-3);
    else cout << n*(n-1)*(n-2);

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