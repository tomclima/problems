/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){

    int n; cin >> n;
    string s; cin >>s;
    int i = 1 % n;
    int cnt = 0;
    s = s+s;
    bool repeat = 0;
    for(int i = 0; i <n; i++){
        cnt += s[i] != s[i+1];
        if(s[i] == s[i+1]) repeat = true;
    }

    cout << cnt + (repeat) << endl;

    
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