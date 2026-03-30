/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int x, y;
    int mod3_c = y % 3;
    // diofantine equation -> 9b + 10c = 3x - 2y
    int target = 3*x-2*y;
    bool is_possible = true;
    if(target < 0) is_possible = false;
    
    vector<int> possible_mod9_c;
    int candidate = mod3_c;
    while(candidate < 9 and is_possible){
        possible_mod9_c.push_back(candidate);
        candidate+= 3;
    }

    int target_mod9 = target % 9;

    int match = -1;
    for(auto candidate : possible_mod9_c){
        if(target_mod9 == candidate){
            match = target_mod9;
            break;
        }
    }
    if(!match) is_possible = false;
    if(match > y) is_possible = false;
    
    if(is_possible) cout << "YES" << endl;
    else cout << "NO" << endl;


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