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
    sort(a.begin(), a.end());
    int curr = 0;
    set<int> mex;
    set<int> mex2;
    for(int i = 0; i <= n; i++){
        mex.insert(i);
        mex2.insert(i);
    }
    vector<int> prefix_mex;
    vector<int> suffix_mex;
    bool possible = true;
    for(int i = 0; i < n; i++){
        mex.erase(a[i]);
        prefix_mex.push_back(*mex.begin());
        mex2.erase(a[n-1-i]);
        suffix_mex.push_back(*mex2.begin());
    }
    for(int i = 0; i < n; i++){
        if(prefix_mex[i] == suffix_mex[n-i-2]) possible = false;
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