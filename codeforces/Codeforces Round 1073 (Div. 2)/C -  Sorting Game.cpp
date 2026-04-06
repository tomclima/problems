/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    string s; cin >> s;
    int i = 0;
    
    vector<pair<int, int>> moves;
    for(int j = 0; j< n; j++){
        if(s[i] != '1') i = j;
        else if(j >i+1 and s[j] == '1'){
            moves.push_back({i, j-1});
            i = j;
        }   
    }
    if(i != n-1) moves.push_back({i, n-1});

    bool alice_turn = true;
    bool first_move= true;
    pair<int, int> alice_first;
    int k = 0;
    while(k < moves.size()){
        if((moves.size() - k) % 2 or moves[k].second - moves[k].first + 1 == 2){
            if (first_move) alice_first = moves[k]; 
            k++;
        }
        else{
            if (first_move) alice_first = {moves[k].first, moves[k].second -1}; 
            moves[k].first = moves[k].second -1;
        }
        first_move = 0;
        alice_turn = !alice_turn;
    }

    if(alice_turn) cout << "Bob" << endl;
    else{
        cout << "Alice" << endl;
        cout << alice_first.second - alice_first.first + 1 << endl;
        for(int i = alice_first.first; i <= alice_first.second; i++){
            cout << i+1 << " ";
        }
        cout << endl;
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