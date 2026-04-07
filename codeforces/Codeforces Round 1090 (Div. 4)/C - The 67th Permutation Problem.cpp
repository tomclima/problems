/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    vector<int> a;
    int asz = 3*n-1;
    int sz = n;
    while(sz--){
        a.push_back(asz);
        asz-=2;
    }
    int left = 1;
    int a_idx = 0;
    for(int i = 0; i < 3*n; i++){
        if(i %3 == 1){
            cout << a[a_idx];
            a_idx++;
        }
        if(i %3 == 0){
            cout << left;
            left ++;
        }
        if(i%3 == 2){
            cout << a[a_idx-1] + 1;
        }
        cout << " ";
    }
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