/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    string s; cin >> s;

    if(n == 1) s[0] = '1';
    if(n == 2 and s[0] == '0' and s[1] == '0'){
        s[1] = '1';
    } 
    if(n >= 3){
        if(s[2] == '0' and s[0] == '0') s[1] = '1';
        if(s[1] == '0' and s[2] == '1') s[1] = '1';
    }
    
    int last_one = -1;
    for(int i = 0; i < n; i++){
        if(i - last_one > 2 and (i+1 >= n or s[i+1] != '1')){
            s[i] = '1';
            last_one = i;
        } 
        if(i - last_one >= 2 and i >= n-2) {
            last_one = i;
            s[i] = '1';
        }
        if(s[i] == '1'){
            last_one = i;
        }
    }


    
    int cnt =  0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') cnt++;
    }

    cout << cnt << endl;
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