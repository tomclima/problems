/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

/*
    se nos temos a maior felicidade para para a coleção de dias x
    ao pegarmos x+1 precisamos considerar
    no dia anterior qual foi a atividade escolhida, a outra atividade que 
*/

int solve(){
    int n; cin >> n;
    vector<vector<int>> val(n, vector<int> (3, 0));
    for(auto &v : val){
        for(auto &i : v) cin >> i;
    } 

    vector<vector<int>> dp(n, vector<int> (3, 0));
    dp[0][0] = val[0][0];
    dp[0][1] = val[0][1];
    dp[0][2] = val[0][2];

    for (int i = 1; i < n; i++){
        for(int j = 0; j < 3; j++){
            dp[i][j] = max(dp[i-1][(j+1) %3] + val[i][j], dp[i-1][(j+2) %3] + val[i][j]);
        }
    }

    cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);

    

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