/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> vec;
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r;
        vec.push_back({l, r});
    }
    sort(vec.begin(), vec.end());

    
    int l = vec[0].first;
    int r = vec[0].second;
    for(int i = 1; i < m; i++){
        l = vec[i].first;
        r = min(vec[i].second, r);
        if(r < l){
            break;
        }
    }

    if(r < l) cout << 0;
    else{
        cout << r - l + 1;
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