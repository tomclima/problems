/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    int n, m; cin >> n >> m;

    vector<pair<int, int>> movies;
    for(int i = 0; i < n; i++){
        int l, r; cin >> l, r;
        movies.push_back({l, r});
    }

    auto f = [](auto &a, auto &b){
        return a.first < b.first;
    };

    stable_sort(movies.begin(), movies.end(), f);
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }
}