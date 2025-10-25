/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        set<char> appeared;
        int n; cin >> n;
        string s; cin >> s;
        bool sus = false;
        for(int i = 0; i < n; i++){
            if(i> 0 and s[i] != s[i-1] and appeared.find(s[i]) != appeared.end()){
                sus = true;
            }
            appeared.insert(s[i]);
        }

        if(sus) cout << "NO" << endl;
        else cout << "YES" << endl;

    }


}