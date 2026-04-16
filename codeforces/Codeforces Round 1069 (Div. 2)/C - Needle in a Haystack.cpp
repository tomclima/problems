/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    string s, t; cin >> s >> t;
    map<char, int> chars;

    string ans;

    for(auto c : t) chars[c]++;;

    bool possible = true;
    for(auto c :s){
        chars[c]--;
        if(chars[c] < 0) possible = false;
    }

    if(!possible){
        cout << "Impossible" << endl;
        return 0;
    }
    set<string> collect;
    for(auto c: chars){
        string a;
        while(c.second--){
            a += c.first;
        }
        collect.insert(a);
    }

    for(auto c : s){
        while(!collect.empty() and *collect.begin() < string(1, c)){
            ans += *collect.begin();
            collect.erase(collect.begin());
        }
        ans += c;
    }
        while(!collect.empty()){
        ans += *collect.begin();
        collect.erase(collect.begin());
    }

    cout << ans << endl;
    

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