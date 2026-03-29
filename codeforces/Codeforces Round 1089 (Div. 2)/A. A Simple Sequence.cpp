/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

/*
    99 100 
*/

int solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cout << n - i << " ";
    }
    cout << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}