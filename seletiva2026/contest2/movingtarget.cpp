/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){    
    int n; cin >> n;
    cout << n/2+1 << endl;
    for(int i = 1; i+2 <= n+1; i+=2){
        cout << i << " ";
    }
    cout << n;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t =1;// cin >> t;
    while(t--){
        solve();
    }
}