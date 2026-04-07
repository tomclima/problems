/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    
    int best = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((a[i] ^ a[j] )> best) best =a[i] ^ a[j];
        }
    }

    cout << best << endl;
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