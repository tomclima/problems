/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    map<int, int> pos;
    vector<int> arr;
    vector<int> longest_size(n, 0);
    vector<int> start_longest(n, -1);

    for(int i = 0; i < n; i++){
        int val; cin >> val;
        arr.push_back(val);
    }

    longest_size[0] =1;
    pos[arr[0]] = 0;
    start_longest[0] = 0;
    for(int i = 1; i < n; i++){ 
        longest_size[i] = longest_size[i-1] + 1;
        start_longest[i] = start_longest[i-1];

        if(pos.find(arr[i]) != pos.end() and pos[arr[i]] >= start_longest[i]){
            longest_size[i] -= pos[arr[i]] - start_longest[i] + 1;
            start_longest[i] = pos[arr[i]] + 1;
        }

        pos[arr[i]] = i;
    }

    int max = 0;
    for(auto n : longest_size){
        if(n > max) max = n;
    }
    cout << max << endl;
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