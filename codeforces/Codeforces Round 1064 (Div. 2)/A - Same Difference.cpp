/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    string a; cin >> a;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != a[n-1]) cnt++;
    }

    cout << cnt << endl;

    
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