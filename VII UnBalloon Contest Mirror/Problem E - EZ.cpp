#include <bits/stdc++.h>
#define endle "\n"
#define ll long long int
#define pii pair<int, int>

using namespace std;

int solve(){
    
    int n; cin >> n;
    
    vector<int> arr(n);
    for(int i = 1; i <= n; i++){
        arr[i-1] = i;
    }

    reverse(arr.begin(), arr.end());

    int sum = 0;
    for(int i = 0; i < n; i+=2){
        sum += arr[i];
    }

    cout << sum << endl;

    

    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}