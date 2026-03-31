/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

/*
 you have to build it backwards because of the stack overflow
*/



int solve(){
    int n, k; cin >> n >> k;
    vector<int> stones(n);
    for(auto &i : stones) cin >> i;

    sort(stones.begin(), stones.end());

    vector<int> dp(k+1, 0);
    for(int i = 0; i < min(stones[0], k+1); i++) dp[i] = 1;
    for(int i = stones[0]+1; i <= k; i++){
        for (auto stone :stones) {
            if(i - stone < 0) break;
            dp[i] |= dp[i-stone];
        }
        dp[i] = !dp[i];
    }


    bool first_loses = dp[k];
    if(first_loses) cout << "Second" << endl;
    else cout << "First" << endl;
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