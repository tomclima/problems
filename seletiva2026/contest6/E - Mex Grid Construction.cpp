/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int get_mex(set<int> &s1, set<int> &s2){
    for(auto i : s1){
        if(s2.find(i) != s2.end()){
            return i;
        }
    }

    return -1;
}

int solve(){
    int n; cin >> n;

    // sets with all elements not included
    vector<set<int>> lines(n);
    vector<set<int>> collumns(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n*n+1; j++){
            lines[i].insert(j);
            collumns[i].insert(j);
        }
    }

    vector<vector<int>> grid(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int mex = get_mex(collumns[j], lines[i]);
            collumns[j].erase(mex);
            lines[i].erase(mex);
            grid[i][j] = mex;
        }
    }

    for(int i = 0; i < n;i++){
        for(int j = 0;j < n; j++){
            cout << grid[i][j] << " ";
        }
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