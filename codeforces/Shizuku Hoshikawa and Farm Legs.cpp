/*
n legs

2*chickens + 4*cows = n

only chickens is always possible

3, 0
1, 1

...



*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    int n; cin >> n;
    int k = 0;
    while(n % 2 == 0 and n/2 - 2*k >= 0){
        k++;
    } 

    cout << k << endl;
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