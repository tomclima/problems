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
    vector<bool> has_inversion(n);

    int inversions = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[i]) has_inversion[i] = true;
        }
    }

    for(int inv : has_inversion) inversions += inv; 

    cout << inversions << endl;


    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;  cin >> t;
    while(t--){
        solve();
    }
}