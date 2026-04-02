/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;
    
    // process the ones
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(i + arr[i] < n and arr[i + arr[i]] == 1) cnt++;
    }

    // process the rest
    /*
        n*n/2
    */
    for(int i = 0; i < n; i++){
        if(arr[i] >= 1){
            int j = i;
            while(j - arr[i] >= 0){
                j-= arr[i];
                if(arr[j]*arr[i] == i-j) cnt++;
            }
        }
    }

    cout << cnt << endl;    

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