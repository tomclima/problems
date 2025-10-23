/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

ll pow10(int n){
    ll a = 1;
    int k = n;
    while(k--){
        a *= 10;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q; cin >> q;
    while(q--){
        ll k; cin >> k;
        int i = 0;
        while(k > 0 and i < 20){
            i++;
            k -= i * pow10(i-1)*9;
        }
        if(k == 0){
            cout << "9" << endl;
        }
        else{
            k += i*pow10(i-1)*9;
            k--;
            ll val = pow10(i-1) + k/i;
            int shift = k % i;
            cout << (val/pow10(i - shift -1))%10 << endl;
        }
    }
}