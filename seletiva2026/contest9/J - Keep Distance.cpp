/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


vector<vector<int>> all_arrays;
int counting = 0;
void backtrack(int n, int m, vector<int> curr_arr){
    if(n == 0){
        all_arrays.push_back(curr_arr);
        counting++;
        return;
    }

    int i = 1;
    if (!curr_arr.empty()) i = curr_arr.back() + 10;

    while(i + 10*(n-1) <= m){
        curr_arr.push_back(i);
        backtrack(n-1, m, curr_arr);
        i += 1;
        curr_arr.pop_back();
    }

    return;
    
}

int solve(){
    int n, m; cin >> n >> m;

    vector<int> arr;
    backtrack(n, m, arr);

    cout << counting << endl;
    for(int i = 0; i < counting; i++){
        for(auto j : all_arrays[i]) cout << j << " ";
        cout << endl;
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