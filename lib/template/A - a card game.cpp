/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN



int solve(){
    int n; cin >> n;
    long double val = 0;
    for(int i = 1; i <= n; i+=1){
        long double sum = (long double)(((long double)i * (i-1))/n);
        val += sum;
    }

    cout << fixed << setprecision(6) <<  val;
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