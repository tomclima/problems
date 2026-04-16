/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n, h, l; cin >> n >> h >> l;
    vector<int> a(n);
    int row_vals = 0;
    int col_vals = 0;
    int either_vals = 0;


    for(int i = 0; i < n; i++){
        int k; cin >> k;
        if (k<= h and k > l) row_vals++;
        else if(k <= l and k > h) col_vals++;
        else if(k <= l and k <= h) either_vals++;
    }

    if(row_vals < col_vals) {
        int a = min(either_vals, col_vals - row_vals);
        either_vals -= a;
        row_vals += a;
    }
    else if(col_vals < row_vals){
        int a= min(either_vals, row_vals - col_vals);
        either_vals -= a;
        col_vals += a;

    }

    while(either_vals -2 >= 0){
        either_vals -=2;
        row_vals++;
        col_vals++;
    }

    cout << min(col_vals, row_vals) << endl;



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