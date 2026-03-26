/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 2*100000*1000000000



int solve(){
    int n; cin >> n;
    vector<ll> h(n+1);
    vector<int> r_increasing(n+1);
    stack<int> monotonic;
    monotonic.push(0);
    h[0] = 0;
    for(int i = 1; i < n+1; i++){
        cin >> h[i];
        while(h[i] < h[monotonic.top()]){
            r_increasing[monotonic.top()] = i;
            monotonic.pop();
        }
        monotonic.push(i);
    }

    while(!monotonic.empty()){
        r_increasing[monotonic.top()] = n+1;
        monotonic.pop();
    }


    vector<int> l_increasing(n+1);
    stack<int> monotonic2;
    monotonic2.push(n+1);
    h.push_back(0);
    h[0] = 0;
    for(int i = n; i >= 0; i--){
        while(h[i] < h[monotonic2.top()]){
            l_increasing[monotonic2.top()] = i;
            monotonic2.pop();
        }
        monotonic2.push(i);
    }

    while(!monotonic2.empty()){
        l_increasing[monotonic2.top()] = 0;
        monotonic2.pop();
    }

    

    ll best = 0;
    for(int i = 1; i < n+1; i++){
        ll candidate = (r_increasing[i] -1  - l_increasing[i])*h[i];
        if ( candidate > best) best = candidate;
    }

    cout << best << endl;



    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}