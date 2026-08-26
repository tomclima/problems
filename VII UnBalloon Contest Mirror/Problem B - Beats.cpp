#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
#define pii pair<int, int>

using namespace std;

int solve(){   
    
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    while(q--){
        
        int query, l, r; cin >> query >> l >> r;

        l--;
        r--;

        if(query == 1){
            int x; cin >> x;
            for(int i = l; i<=r; i++){
                arr[i] = arr[i] % x;
            }
        }
        if(query == 2){
            int x; cin >> x;
            for(int i = l; i <=r; i++){
                arr[i] = max(arr[i], x);
            }

        }
        if (query == 3){
            ll total_sum = 0;
            for(int i = l; i <= r; i++){
                total_sum += arr[i];
            }
            cout << total_sum << endl;
        }
    }
    
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