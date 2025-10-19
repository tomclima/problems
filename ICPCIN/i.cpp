/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;


    vector<ll> language;
    for (int i = 0; i < n; i++){
        ll num; cin >> num; 
        language.push_back(num);
    }

    vector<ll> prefix_sum;
    prefix_sum.push_back(0);
    for(int i = 0; i < n; i++){
        prefix_sum.push_back(prefix_sum[i] + language[i]);
    }

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        
        ll n = r - l + 1;
        ll sum = (n + 1)*(n)/2;
        if(prefix_sum[r] - prefix_sum[l-1] == sum){
            cout << "TAK" << endl;
        } 
        else{
            cout << "NIE" << endl;
        }
    }

}