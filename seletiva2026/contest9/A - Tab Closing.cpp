
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


int solve(){

    ll a, b, m; cin >> a>> b>>m;
    
    ll changepoint;

    if(a % b == 0) changepoint = a/b -1;
    else{
        changepoint = a/b;
    }

    ll times;
    if(m > changepoint){
        times = m - changepoint + 1;
    }
    else{
        times = m;
    }

    if(times == 1) cout << times;
    else if(b >= a or m==1 or b*m <= a) cout << "1";
    else cout << "2";
    cout << endl;


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