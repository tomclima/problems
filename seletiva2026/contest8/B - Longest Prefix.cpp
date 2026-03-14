/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    string s1, s2;

    cin >> s1 >> s2;

    map <char, int> s2_chars;
    
    for(int i = 0; i < s2.length(); i++){
        s2_chars[s2[i]]++;
    }
    int count = 0;
    for(int i = 0; i < s1.length(); i++){
        if (s2_chars[s1[i]] > 0){
            s2_chars[s1[i]] --;
            count++;
        }
        else{
            break;
        }
    }

    cout << count << endl;
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