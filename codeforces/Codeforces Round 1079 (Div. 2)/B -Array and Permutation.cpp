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
    for(auto &i : a) cin >> i;
    
    vector<int> ans = p;
    for(int i = 0; i < n-1; i++){
        if(p[i] == a[i+1]){
            ans[i+1] = p[i];
        } 
        
    }
    for(int i = n-1; i > 0; i--){
        if(p[i] == a[i-1]) {
            ans[i-1] = p[i];
        }
    }

    for(int i = 0; i < n-1; i++){
        if(ans[i] == a[i+1]){
            ans[i+1] = ans[i];
        }
    }
    for(int i = n-1; i > 0; i--){
        if(ans[i] == a[i-1]){
            ans[i-1] = ans[i];
        }

    }

    int equal = true;
    for(int i = 0; i < n; i++){
        if(ans[i] != a[i]) equal = false;
    }

    if (equal) cout << "YES" << endl;
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