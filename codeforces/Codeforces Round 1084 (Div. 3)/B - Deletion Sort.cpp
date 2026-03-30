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
    
    int found = false;
    int rightmost = -1;
    for(int i = n-1; i >= 0 and !found; i--){
        for(int j = 0; j < i and !found; j++){
            if(a[i] < a[j]){
                found = true;
                rightmost = i;
            }
        }
    }

    if(!found){
        cout << n << endl;
    }
    else{
        cout << 1 << endl;
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