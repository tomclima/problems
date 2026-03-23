/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define vec vector<ll> 
#define ld long double



ll vec_cross_product(vec v1, vec v2, vec v3){
    return (v2[0] - v1[0]) * (v3[1] - v1[1]) - (v2[1] - v1[1]) * (v3[0] - v1[0]);
}

int solve(){
    int n; cin >> n;


    while(n--){
        vec p1(2), p2(2), p3(2);


        cin >> p1[0] >> p1[1] >> p2[0] >> p2[1] >> p3[0] >> p3[1];

        ll cross = vec_cross_product(p1, p2, p3);
        
        if (cross > 0) cout << "LEFT";
        else if (cross < 0) cout << "RIGHT";
        else cout << "TOUCH";
        cout << endl;

    }

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