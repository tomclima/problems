/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

//next permutatiopn

int solve(){
    int n; cin >> n;
    vector<int> perms;
    for(int i = 0; i < n; i++){
        perms.push_back(i+1);
    }

    while(next_permutation(perms.begin(), perms.end())){

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