/*
1 a b c d e 5
1 2 3 4 5 6 5
bi = (2 - 1) + (3 - 2) + (...)

(a - 1) + (b - a) + (c - b) + (d - c) + (e - d) + (5 - e)

= 5 - 1 = 4

mas queremos o modulo da diferença

*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXVAL 1000000

int solve(){
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        if(val == -1 and i > 0 and i < n-1) val = 0;
        arr.push_back(val);
    }

    if(arr[0] == -1 and arr.back() == -1){
        arr[0] = 0;
        arr.back() = 0;
    }
    else if(arr[0] == -1 and arr.back() != -1){
        arr[0] = arr.back();
    }
    else if(arr[0] != -1 and arr.back() == -1){
        arr.back() = arr[0];
    }

    cout << abs(arr.back() - arr[0]) << endl;
    for(int i = 0; i < n -1; i++){
        cout << arr[i] << " ";
    }
    cout << arr.back() << endl;

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