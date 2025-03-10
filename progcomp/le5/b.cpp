/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    for(int k = 0; k < t; k++){
        string s1;
        string s2;

        getline(cin, s1);
        if(s1.empty()) s1 = "";

        getline(cin, s2);
        if(s2.empty()) s2 = "";

        vector<vector<int>> dp;
        dp.resize(s1.length() +1);
        for(int i = 0; i < dp.size(); i++){
            dp[i].resize(s2.length() + 1);
        }
    
        for(int i = 0; i < s1.length() + 1; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j < s2.length() + 1; j++){
            dp[0][j] = j;
        }
    
        for(int i = 1; i < s1.length() + 1; i++){
            for(int j = 1; j < s2.length() + 1; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1;
                    int a = min(dp[i][j-1], dp[i-1][j]);
                    dp[i][j] += min(a, dp[i-1][j-1]);
                }
            }
        }
    
        int a = dp[s1.length()][s2.length()];
        cout << a << endl;
    }
    
}