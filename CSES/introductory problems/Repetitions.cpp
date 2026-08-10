/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    string s; cin >> s;


    char curr_char = 'p';
    int curr_seq = 0;
    int max_seq = 0;

    for(auto &c : s){
        
        if (c == curr_char) curr_seq++;
        else (curr_seq = 1);
        curr_char = c;


        if (curr_seq > max_seq) max_seq = curr_seq;
    }

    cout << max_seq;
    

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}