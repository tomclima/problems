/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    ll n; cin >> n;
    ll k; k = n;
    vector<ll> even;
    vector<ll> odd;
    
    //handle degenerated cases
    for(int i = 0; i < n; i++){
        ll a; cin >>a;
        if(a%2) odd.push_back(a);
        else even.push_back(a);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    reverse(even.begin(), even.end());
    reverse(odd.begin(), odd.end());
    
    if(odd.empty()){
        while(k--){
            cout << 0 << " ";
        }
        cout << endl;
        return 0;
    }
    if(even.empty()){
        for(int i = 1; i <= k; i++){
            if(i%2) cout << odd[0];
            else cout << 0;
            cout << " ";
        }
        cout << endl;
        return 0;
    }
    


    // best possible array
    vector<ll> best;
    vector<ll> prefix;
    best.push_back(odd[0]);
    
    for(int i = 0; i< even.size(); i++){
        best.push_back(even[i]);
    }
    prefix.push_back(0);
    for(int i = 0; i < best.size(); i++){
        prefix.push_back(prefix[i] + best[i]);
    }

    for(int i = 1; i <= k; i++){
        // if k <= best.size
        if(i <= best.size()){
            cout << prefix[i];
        }
        // if k > best.size()
        else{
            int diff = i - best.size();
            

            int how_many_odd = ((odd.size() - 1)/2)*2;
            
            if(diff <= how_many_odd and diff % 2){
                diff = -1;
            }
            else if(diff <= how_many_odd){
                diff = 0;
            }
            
            if(diff <= 0){
                cout << prefix[best.size()+diff];
            }
            else{
                cout << 0;
            }

        }
        cout << " ";
    }
    cout << endl;


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