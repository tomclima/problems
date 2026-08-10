/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000



string bit_rep(int n, int bits){
    
    string rep = "";
    for(int i =0; i < bits; i++){
        if (n % 2 == 0){
            rep += "0";
        }
        else{
            rep += "1";
        }
        n /= 2;
    }

    return rep;
}

int solve(){
    
    int n; cin >> n;
    vector<bool> visited((1 << n));
    stack<int> next;
    next.push(0);
    vector<int> order;
    while(!next.empty()){
        
        int curr = next.top();
        
        next.pop();

        if(visited[curr]) continue;

        visited[curr] = true;
        order.push_back(curr);
        for(int i = 0; i < n; i++){
            if(!visited[curr ^ (1 << i)]){
                next.push(curr ^ (1 << i));
            }
        }
    }

    for(auto i: order){
        cout << bit_rep(i, n) << endl;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}