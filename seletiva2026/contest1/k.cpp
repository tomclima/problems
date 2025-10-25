/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        sum += val;
    }

    for(int i = 0; i < n; i++){
        if(sum % (n-i) == 0){
            cout << i;
            break;
        }
    }
}