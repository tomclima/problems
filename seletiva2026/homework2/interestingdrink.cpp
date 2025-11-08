/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int


int solve(){

    int n; cin >> n;
    vector<ll> x;
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        x.push_back(val);
    }

    sort(x.begin(), x.end());

    int q; cin >> q;
    for(int i = 0; i < q; i++){
        ll m; cin >> m;

        int qtd = upper_bound(x.begin(), x.end(), m) - x.begin();
        cout << qtd << endl;
    }


    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;// cin >> t;
    while(t--){
        solve();
    }
}