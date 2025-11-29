/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    ll x, a, b, c; cin >> x >> a >> b >> c;
    vector<ll> prefix;
    vector<ll> array;
    array.push_back(x);
    prefix.push_back(0);

    for(int i = 1; i <= n; i++){
        array.push_back((a*array[i-1] + b) % c);
        ll val = array.back();
        prefix.push_back(prefix[i-1] ^ (array[i-1]));
    }

    ll xored = 0;
    for(int i = 0; i+k < prefix.size(); i++){
        xored ^= prefix[i+k] ^ prefix[i];
    }

    cout << xored;
}