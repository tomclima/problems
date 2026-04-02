/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    map<int, int> cnt;
    bool possible = true;
    for(int i = 0; i < n*n; i++){
        int a; cin >> a;
        cnt[a]++;
        if(cnt[a] > n*n - n) possible =  false;
    }
    if(possible) cout << "YES" << endl;
    else{
        cout << "NO" << endl;
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