/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    vector<int> arr;
    vector<int> members(n);
    ll total_sum = 0;
    for(int i = 0; i < n; i++){
        arr.push_back(n - i);
        total_sum += n-i;
    }

    if(total_sum % 2 != 0){
        
        cout << "NO" << endl;
    }
    else{
        
        ll target = total_sum/2;
        ll curr_sum = 0;
        for(int i = 0; i < n; i++){
            
            if (curr_sum + arr[i] < target){

                curr_sum += arr[i];
                members[i] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] == target - curr_sum){
                members[i] = 1;
            }
        }
        
        vector<int> arr1, arr2;
        for(int i = 0; i < n; i++){
            if(members[i]) arr1.push_back(arr[i]);
            else arr2.push_back(arr[i]);
        }

        cout << "YES" << endl;
        cout << arr1.size() << endl;
        for(auto i : arr1){
            cout << i << " ";
        }
        cout << endl;
        cout << arr2.size() << endl;
        for(auto i : arr2){
            cout << i << " ";
        }
        cout << endl;

    }


    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}