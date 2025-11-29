/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int a, b, c; cin >> a >> b >> c;
    int divisors = 0;

    for(int i = a; i <= b; i++){
        if(c%i == 0) divisors++;
    }

    cout << divisors << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}