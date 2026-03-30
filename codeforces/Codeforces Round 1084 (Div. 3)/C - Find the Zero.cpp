/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    int i = 1;

    int original = 2*n;

    bool found = false;
    while(!found and n--){
        cout << "? " << i << " " << i+1 << endl; 
        bool result; cin >> result;
        found = result;
        i++;
    }
    if (!found){
        cout << "!" << " " << original << endl;
    }
    else{
        cout << "! " << i << endl;
    }

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