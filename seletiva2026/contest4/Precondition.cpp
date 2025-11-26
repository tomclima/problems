/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int




int solve(){
    set<char> upper {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' , 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    string s1, s2; cin >> s1 >> s2;
    set<char> chars2;
    for(auto &chr : s2){
        chars2.insert(chr);
    }
    bool correct = true;
    for(int i = 0; i < s1.length(); i++){
        if(i > 0 and upper.find(s1[i]) != upper.end()){
            if (chars2.find(s1[i-1]) == chars2.end()) correct = false;
        }
    }

    if(correct) cout << "Yes";
    else cout << "No";
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