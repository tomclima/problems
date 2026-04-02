/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    int result = -1;
    for(int i = 1; i < n; i++){
        cout << "? " << 2*i +1<< " " << 2*i +2 << endl;
        int ans; cin >> ans;
        if(ans == 1) result = 2*i+1;
        if (result != -1){
            cout << "! " << result << endl;
            return 0;
        }
    }
    if(result == -1){
        cout << "? " << 1 << " " << 3 << endl;
        int ans; cin >> ans;
        if(ans == 1) result = 1;
        cout << "? " << 1 << " " << 4 << endl;
        cin >> ans;
        if(ans == 1) result = 1;

        if(result == -1){
            cout << "! " << 2 << endl;
        }
        else{
            cout << "! " << result << endl;
        }
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