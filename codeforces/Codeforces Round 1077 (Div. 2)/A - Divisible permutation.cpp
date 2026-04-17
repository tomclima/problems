/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    vector<int> a(n);
    a[0] = 1;
    set<int> used;
    used.insert(a[0]);
    for(int i = 1; i < n; i++){
        a[i] = abs(a[i-1] + (n) - i);
        if(a[i] > n or used.find(a[i]) != used.end()) a[i] = a[i-1] + i - n;
        used.insert(a[i]);
    }

    reverse(a.begin(), a.end());
    for(auto &i: a) cout << i << " ";
    cout << endl;
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