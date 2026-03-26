/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int

int solve(){
    int n; cin >> n;
    
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int val; cin >> val;
        arr.push_back(val);
    }

    int first = arr[0];
    int last = arr.back();

    vector<int> middle;
    for(int i = 1; i < n-1; i++){
        middle.push_back(arr[i]);
    }

    sort(middle.begin(), middle.end());

    int curr = first;
    int i = -1;
    int dominoes = 1;
    bool changed = true;
    while(2*curr < last and changed and !middle.empty()){
        int target = upper_bound(middle.begin(), middle.end(), 2*curr) - middle.begin();
        target--;
        if (target == i) changed = false;
        i = target;
        dominoes++;
        curr = middle[target];
    }

    if(2*curr < last){
        cout << -1 << endl;
    }
    else{
        cout << dominoes +1 << endl;
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

    return 0;
}