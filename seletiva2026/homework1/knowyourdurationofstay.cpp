/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){

    int n, m; cin >> n >> m;
    vector<ll> prefix_days;
    vector<ll> months;
    prefix_days.push_back(0);
    for(int i = 1; i <= n; i++){
        ll val; cin >> val;
        months.push_back(val);
        prefix_days.push_back(prefix_days[i-1] + val);
    }

    for(int i = 0; i < m; i++){
        ll sd, sm, ed, em; cin >> sd >> sm >> ed >> em;
        ll days = 1;

        if(sm == em and sd <= ed){ // special case
            days += ed - sd;
            cout << days << endl;
            continue;
        }
        
        days += months[sm-1] - sd + ed;
        if(em > sm){
            days += prefix_days[em -1] - prefix_days[sm];
            cout << days << endl;
            continue;
        }
        
        if(em <= sm){
            days += prefix_days.back() - prefix_days[sm];
            days+= prefix_days[em-1];
            cout << days << endl;
            continue;
        }
        
        
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        solve();
    }
}