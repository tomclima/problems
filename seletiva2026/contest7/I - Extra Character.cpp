/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    
    string s1, s2; cin >> s1 >> s2;

    int diff = -1;
    for(int i = 0; i < s1.size() and diff == -1; i++){
        if(s1[i] != s2[i]){
            diff = i;
        }
    }

    if(diff == -1) cout << s1.size() +1;
    else{
        cout << diff +1;
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