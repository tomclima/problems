/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    int n; cin >> n;
    stack<int> station_a;
    stack<int> station_b;
    stack<int> station_c;
    station_c.push(0);

    for(int i = 0; i < n; i++){
        int val; cin >> val;
        station_a.push(val);
    }  

    bool possible = true;
    vector<string> moves;
    while(station_c.size() < n+1 and possible){
        if(station_a.size() == 0 and station_b.top() != station_c.top() + 1){
            possible = false;
        }
        else if (station_a.size() != 0 and station_a.top() == station_c.top() + 1){
            moves.push_back("A C");
            station_c.push(station_a.top());
            station_a.pop();
        }
        else if(station_b.size() != 0 and station_b.top() == station_c.top() + 1){
            moves.push_back("B C");
            station_c.push(station_b.top());
            station_b.pop();
        }
        else {
            moves.push_back("A B");
            station_b.push(station_a.top());
            station_a.pop();
        }
    }

    if(!possible) cout << "-1" << endl;
    else{
        cout << moves.size() << endl;
        for(auto move : moves){
            cout << move << endl;
        }
    }
    
    
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; t = 1;//cin >> t;
    while(t--){
        solve();
    }
}