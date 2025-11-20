/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){
    int n; cin >> n;
    vector<int> perm;
    map<int, int> indices;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        indices[val] = i;
        perm.push_back(val);
    }
    
    if(indices[n] > indices[1]){
        cout << "Yes" << endl;
        return 0;
    }

    bool possible = true;

    int biggest_after_1 = -1;
    for(int i = indices[1]; i < n; i++){
        if(perm[i] > biggest_after_1) biggest_after_1 = perm[i];
    }
    possible &= (biggest_after_1 > -1);
    

    int smallest_before = 1e6;
    for(int i = 0; i < indices[n]; i++){
        if(perm[i] < smallest_before) smallest_before = perm[i];
    }
    possible &= smallest_before < 1e6;

    int biggest_between = - 1;
    int smallest_between = 1e6;
    for(int i = indices[n]+1; i < indices[1]; i++){
        if(perm[i] > biggest_between) biggest_between = perm[i];
        if(perm[i] < smallest_between) smallest_between = perm[i];
    }
    

    possible &= (smallest_before < biggest_between and smallest_before < biggest_after_1);

    if (possible){
        cout << "Yes" << endl;
    } 
    else{
        cout << "No" << endl;
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