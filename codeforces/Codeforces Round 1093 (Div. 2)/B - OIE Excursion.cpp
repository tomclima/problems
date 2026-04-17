/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &i: a) cin >> i;
    set<int> exclude;
    for(int i = 0; i < n; i++){
        exclude.insert(k - (a[i] + i+1) % k);
    }

    if(exclude.size() >= k) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
    }
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