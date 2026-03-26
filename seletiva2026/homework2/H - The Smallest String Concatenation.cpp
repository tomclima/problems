/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

bool my_comparator(const string &s1, const  string &s2){
    string concat1 = s1 + s2;
    string concat2 = s2 + s1;
    return concat1 < concat2;
}

int solve(){
    int n; cin >> n;
    vector<string> s(n);
    for(auto &str : s) cin >> str;
    sort(s.begin(), s.end(), my_comparator);
    string concat;
    for(auto str : s){
        concat += str;
    }

    cout << concat;
    
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