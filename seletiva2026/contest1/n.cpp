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
        ll y, x; cin >> y >> x;

        ll n = max(x, y);

        ll prog_two = (2 + 2*(n-1))*(n -1)/2;

        ll corner_val = 1 + prog_two;

        bool up_increases = n%2;
        

        ll ans;
        if(up_increases and y < n){
            ans = corner_val + ((n - y));
        }
        else if(!up_increases  and y < n){
            ans = corner_val - (n - y);
        }
        else if(up_increases and x < n){
            ans = corner_val - (n - x);
        }
        else if(!up_increases and x < n){
            ans = corner_val + (n - x);
        }
        else {
            ans = corner_val;
        }

        cout << ans<< endl;
    }
}