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
        ll a, b; cin >> a >> b;
        if(a == b) cout << 0 << endl;
        else if (a > b) cout << 1 + (a%2 != b%2) << endl;
        else cout << 1 + (a%2 == b%2) << endl;
        
    }
}