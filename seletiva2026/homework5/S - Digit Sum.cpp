/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int target;

ll mod = (ll)1000000000+7;



int solve(){
    int k; cin >> k >> target;
    vector<int> digits;
    int ck = k;
    while(ck){
        digits.push_back(ck % 10);
        ck /= 10;
    }
    digits.push_back(0);
    reverse(digits.begin(), digits.end());
    
    
    vector<vector<ll>> dp(digits.size() + 1, vector<ll> (target, 0));
    dp[0][0] = 1;
    for(int i = 1; i < digits.size(); i++){
        for(int j = 0; j < target; j++){
            if(i*9 + j < target) dp[i][j] = 0;
            if((i*9 + j )% target == 0) dp[i][j] = 1;
            else{
                for(int k  = 0; k < 9; k++){
                    dp[i][j] += dp[i-1][(j+k) % target]*((i>1) + (9-j)/target);
                }
            }
        }
    }

    ll sum = dp[digits.size()][0];


    cout << sum << endl;

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