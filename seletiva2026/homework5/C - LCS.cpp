/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define UNDEF -1

vector<vector<int>> dp;
string str_a, str_b;

int lcs(int a, int b){
    if(dp[a][b] != UNDEF) return dp[a][b];
    if(a == 0 or b == 0) return dp[a][b] = 0;


    bool is_equal = str_a[a-1] == str_b[b-1]; 
    int lcs_size = 0;
    if(is_equal){
        lcs_size = max(lcs_size, is_equal + lcs(max(a-1, 0), max(b-1, 0)));
    }
    else{
        lcs_size = max(lcs_size, is_equal + lcs(a, max(b-1, 0)));
        lcs_size = max(lcs_size, is_equal + lcs(max(a-1, 0), b));
    }

    return dp[a][b] = lcs_size;
}

void recover_lcs(int a, int b, string &build){    
    if(a == 0 or b == 0) return;
    
    
    bool is_equal = str_a[a-1] == str_b[b-1];
    if(is_equal){
        build += str_a[a-1];
        recover_lcs(a-1, b-1, build);
        return;
    }

    // else
    if(lcs(a, max(b-1, 0)) > lcs((max(a-1, 0)), b)) recover_lcs(a, max(b-1, 0), build);
    else recover_lcs(max(a-1, 0), b, build);

}

int solve(){
    cin >> str_a >> str_b;
    for(int i = 0; i <= str_a.size(); i++){
        vector<int> line;
        dp.push_back(line);
        for(int j = 0; j <= str_b.size(); j++){
            dp[i].push_back(UNDEF);
        }
    }

    lcs(str_a.size(), str_b.size());
    string ans; recover_lcs(str_a.size(), str_b.size(), ans);

    reverse(ans.begin(), ans.end());
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