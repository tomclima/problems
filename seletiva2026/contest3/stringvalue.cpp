/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    int n; cin >> n;
    string s; cin >> s;
    ll max_count = 1;
    ll count_freq = 1;
    char curchar = s[0];
    for(int i = 1; i < n; i++){
        if(s[i] == curchar) {
            count_freq++;
            if(count_freq > max_count) max_count = count_freq;
        }
        else{
            count_freq = 1;
            curchar = s[i];
        }
    }

    cout << max_count << endl;
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