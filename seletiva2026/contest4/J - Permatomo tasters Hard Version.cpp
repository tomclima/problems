/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

// TODO: UPSOLVE THIS. THIS SOLUTION IS WRONG

int solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> prefix(n+1);
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + 2*(n-i) + 1;
    }

    int bucket = lower_bound(prefix.begin(), prefix.end(), k) - prefix.begin();
    bucket--;
    int pos = k - prefix[bucket];
    
    cout << a[bucket] + a[bucket + (pos/2)] << endl;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}