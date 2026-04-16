/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    set<int> a;
    for(int i = 0; i < n; i++){
        int v; cin >> v;
        a.insert(v);   
    }
    int w = *a.lower_bound(a.size());
    cout << w << endl;
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