/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n = 7;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    
    int sum = 0;
    for(int i = 0; i < n-1; i++){
        sum -= a[i];
    }
    sum += a.back();


    cout << sum << endl;
    
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