/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){

    int n, k; cin >> n >> k;
    vector<int> bags;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        bags.push_back(val);
    }
    
    bool parity = bags[0] % 2;
    vector<priority_queue<int>> sequences;
    sequences.push_back(priority_queue<int>());
    for(int i = 0; i < n; i++){
        if(bags[i] % 2 == parity) sequences.back().push(bags[i]);
        else{
            parity = bags[i] % 2;
            sequences.push_back(priority_queue<int>());
            sequences.back().push(bags[i]);
        }
    }
    
    int max_balls = 0;
    for(auto seq : sequences){
        for(int i = 0; i < k and !seq.empty(); i++){
            max_balls += seq.top();
            seq.pop();
        }
    }

    cout << max_balls << endl;


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