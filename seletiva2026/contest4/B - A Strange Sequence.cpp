/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

ll decode_coord(string str){
    ll x = str.back() - 'a';
    ll y = (ll)stoi(str.substr(0, str.size() -1));
    return y*26 + x;
}

int solve(){
    string str; cin >> str;
    ll coord = decode_coord(str);

    ll last_k = -1;
    ll k = 4;
    ll i = 0;
    while(k < coord){
        last_k = k;
        k = k + (3 + 2*i);
        i++;
    }
    if(last_k != coord and k != coord){
        cout << -1 << endl;
    }
    else if(last_k == coord){
        cout << i << endl;
    }
    else{
        cout << i+1 << endl;
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