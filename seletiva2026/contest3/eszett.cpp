/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

void dfs(const string &s, set<string> &visited){
    visited.insert(s);
    cout << s << endl;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 's' and s[i+1] == 's'){
            string newstr = (s.substr(0, i)) + "B" + s.substr(i+2, s.size() - (i+2));
            if((visited.find(newstr) == visited.end())){
                dfs(newstr, visited);
            }
        }
    }
}


int solve(){
    string s; cin >> s;
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c){return tolower(c);});

    set<string> visited;
    dfs(s, visited);

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