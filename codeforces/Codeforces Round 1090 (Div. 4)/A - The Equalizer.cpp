/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);

    for(auto &i : a) cin >> i;
    ll sum = 0;
    for(auto &i : a) sum+=i;
    if(sum %2 or (n*k) %2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;  cin >> t;
    while(t--){
        solve();
    }
}