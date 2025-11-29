/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n, q; cin >> n >> q;
    vector<bool> teeth(n, 1);
    for(int i = 0; i < q; i++){
        int val; cin >> val;
        teeth[val-1] = !teeth[val-1];
    }

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += teeth[i];
    }

    cout << sum << endl;
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