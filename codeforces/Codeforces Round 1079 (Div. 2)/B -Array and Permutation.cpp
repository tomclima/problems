/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    vector<int> p(n), a(n);
    for(auto &i : p) cin >> i;
    for(auto &i : a) {cin >> i;}

    vector<int> order_a{a[0]};
    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1]) order_a.push_back(a[i]);
    }

    int j = 0;
    for(int i = 0; i < n; i++){
        if(p[i] == order_a[j]) j++;
    }
    if(j < order_a.size()){
        cout << "NO" << endl;
    }
    else cout << "YES" << endl;
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