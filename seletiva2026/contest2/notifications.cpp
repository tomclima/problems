/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    int n; cin >> n;
    ll time = 0;
    ll prev_t = 0;
    ll prev_l = 0;
    for(int i = 0; i < n; i++){
        int not_t, not_l; cin >> not_t >> not_l;
        if(prev_t + prev_l > not_t){
            prev_t = prev_t + prev_l;
        } 
        else{
            time += not_t - (prev_t+prev_l);
            prev_t = not_t;
        }
        prev_l = not_l;
        time+=not_l;
    }

    cout << time << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t =1;// cin >> t;
    while(t--){
        solve();
    }
}