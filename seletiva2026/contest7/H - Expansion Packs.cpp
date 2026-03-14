/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n, m; cin >> n >> m;
    ll expected_value = 0;
    for(int i = 0; i < n; i++){
        int chance; cin >> chance;
        expected_value += chance;
    }
    
    cout << (long double)(100*m)/expected_value << endl;

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