/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<ll> pos;
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        pos.push_back(val);
    }
    vector<ll> prefix;
    prefix.push_back(0);
    for(int i =1; i <= n; i++){
        ll val; cin >> val;
        prefix.push_back(val + prefix[i-1]);    
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        ll l, r; cin >> l >> r;

        int index_l = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
        int index_r = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

        


        cout << prefix[index_r] - prefix[index_l] << endl;



    }
}