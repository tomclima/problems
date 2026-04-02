/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

/*
    
*/

ll sum_digits(ll b){
    ll sum = 0;
    int copy_b = b;
    while(copy_b){
        sum += copy_b % 10;
        copy_b /= 10;
    }

    return sum;
}

int solve(){
    ll a; cin >> a;
    int no_digits = 0;
    int copy_a = a;
    while(copy_a){
        no_digits++;
        copy_a /= 10;
    }
    int cnt = 0;
    for(ll i = 1; i <= (no_digits + 1)*9; i++){
        if (a == a + i - sum_digits(a + i)) cnt++;
    }  

    cout << cnt << endl;

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
