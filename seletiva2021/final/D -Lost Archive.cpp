/*link*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAXN 1000000000000000000

bool check(ll mid){
    
    cout << "1 ";
    cout << mid << endl;
    fflush(stdout);

    int ans; cin >> ans;
    return ans;
}

int solve(){
    int n; cin >> n;
    
    int l = 1; int r = n+1;
    for (int i = 0; i < 22; i++){
        ll mid = (r + l)/2;
        if (check(mid)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    cout << "! " << (l + r)/2 << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}