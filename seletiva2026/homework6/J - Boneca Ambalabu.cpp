/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

ll BITS = 30;

int solve(){

    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        
        ll val; cin >> val;
        a[i] = val;
    }

    ll option1 = 0;
    ll option2 = 0;
    for(int i = BITS; i >= 0; i--){
        int count_0 = 0;
        int count_1 = 0;
        
        for(auto j : a){
            if(j & (1 << i)) count_1++;
            else count_0++;    
        }
        
        if(count_0 >= count_1){
            option1 |= (1 << i);
            option2 |= (1 << i);  
        }
        if(count_0 == count_1 or count_0 == count_1 + 1){
            option2 ^= (1 << i);
        } 
        
    }

    ll best_score = 0;
    ll best_score_holder = 0;
    for(int i =0; i < n; i++){
        ll curr_score1 = 0;
        ll curr_score2 = 0;
        for(int j = BITS; j >= 0; j--){
            if((a[i] & (1 << j)) == (option1 & (1 << j))) curr_score1 |= (1 << j);
            if((a[i] & (1 << j)) == (option2 & (1 << j))) curr_score2 |= (1 << j);
        }
        
        if(max(curr_score1, curr_score2) > best_score) {
            best_score = max(curr_score1, curr_score2); 
            best_score_holder = i;
        }
    }

    ll max_xor = 0;
    for(int i = 0; i < n; i++){
        max_xor += (a[i] ^ a[best_score_holder]);
    }

    cout << max_xor << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}