/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<int, int>

int solve(){
    int n; cin >> n;
    vector<pii> arr(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        arr[i] = {a, i%2};
    }
    sort(arr.begin(), arr.end());
    bool possible = true;
    for(int i = 1; i < n; i++){
        if(arr[i].second == arr[i-1].second) possible = false;
    }

    if(possible) cout << "YES" << endl;
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