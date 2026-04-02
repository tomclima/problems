/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    set<int> par_open, par_closed;
    set<int> bra_open, bra_closed;

    stack<int> par, bra;
    int i = 0;
    for(auto c : s){
        if(c == '(') par.push(i);
        else if(c == '[') bra.push(i);
        else if(c ==')' and par.empty()) par_closed.insert(i);
        else if(c == ']' and bra.empty()) bra_closed.insert(i);
        else if(c == ')') par.pop();
        else bra.pop(); 
        i++;
    }

    while(!par.empty()){
        par_open.insert(par.top());
        par.pop();
    }
    while(!bra.empty()){
        bra_open.insert(bra.top());
        bra.pop();
    }
    int cnt = 0;

    // open with closed (only need to change one)
    for(auto open : par_open){
        if(bra_closed.upper_bound(open) != bra_closed.end()){
            cnt++;
            bra_closed.erase(bra_closed.upper_bound(open));
            par_open.erase(open);
        }
    }
    for(auto open : bra_open){
        if(par_closed.upper_bound(open) != par_closed.end()){
            cnt++;
            par_closed.erase(par_closed.upper_bound(open));
            bra_open.erase(open);
        }
    }

    //open with open / closed with closed
    for(auto open : par_open){
        if(!bra_open.empty()){
            cnt++;
            bra_closed.erase(bra_closed.upper_bound(open));
            par_open.erase(open);
        }
    }
    for(auto open : bra_open){
        if(par_closed.upper_bound(open) != par_closed.end()){
            cnt++;
            par_closed.erase(par_closed.upper_bound(open));
            bra_open.erase(open);
        }
    }


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