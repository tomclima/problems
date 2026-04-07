/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000




int solve(){
    string a, b; cin >> a >> b;
    vector<vector<int>> dp(a.size()+1, vector<int> (b.size()+1, 0));

    // dp[i][0] = 0
    // dp[0][i] = 0
    
    // building
    for(int i = 1; i < a.size()+1; i++){
        bool found = false;
        for(int j = 1; j < b.size() +1; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + (a[i-1] == b[j-1]);
        }
    }
    
    // reconstructing
    string ans  ="";
    int max = 0;
    for(int i = 1; i < a.size()+1; i++){
        for(int j = 1; j < b.size() + 1; j++){
            if(dp[i][j] > max){
                ans += (a[i-1]);
                max = dp[i][j];
            }
        }
    }

    cout << ans << endl;


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