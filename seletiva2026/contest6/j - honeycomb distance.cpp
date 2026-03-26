/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        int cost = 0;
        if (a>= 0 and b >= 0) cost = a + b;
        else if (a <= 0 and b <= 0) cost = -(a +b);
        else cost = max(abs(a), abs(b));
        
        
        cout << cost << endl;


    }
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