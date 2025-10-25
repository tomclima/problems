/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<ll> arr;
        for(int i = 0; i < n; i++){
            ll val; cin >> val; 
            arr.push_back(val);
        }

        map<int, ll> neigh_diff;
        for(int i = 1; i < n-1; i++){
            neigh_diff[i] = arr[i] - (arr[i-1] + arr[i+1]);
        }
        
        ll tall = 0;
        for(int i = 1; i < n-1; i++){
            if(neigh_diff[i] > 0) tall++;
        }

        if(k > 1){
            cout << tall << endl;
            continue;
        }

        

        


        cout << (n - 1)/2 << endl;
    }
}