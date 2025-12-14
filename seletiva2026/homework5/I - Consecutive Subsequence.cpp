/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


int solve(){
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        arr.push_back(val);
    }
    
    map<int, int> dp;
    for(int i = 0; i < n; i++){
        if(i == 0) dp[arr[i]] = 1;
        else{
            dp[arr[i]] = max(dp[arr[i]], dp[arr[i] -1] + 1);
        }
    }

    int max = 0;
    int max_i = 0;
    for(auto i : arr){
        if(dp[i] > max) {
            max = dp[i];
            max_i = i;
        }
    }

    vector<int> ans;
    int counter = max_i - max +1;
    for(int i = 0; i < n and counter <= max_i; i++){
        if(arr[i] == counter){
            ans.push_back(i +1);
            counter++;
        }
    }
    cout << max << endl;
    for(auto i : ans){
        cout << i << " ";
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