/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int

int solve(){
    int n; cin >> n;
    string s; cin >> s;

    vector<int> prefix_a(1, 0);
    vector<int> prefix_b(1, 0);
    vector<int> diff(1, 0);
    for(int i = 1; i <= n; i++){
        prefix_a.push_back(prefix_a[i-1] + (s[i-1]=='a'));
        prefix_b.push_back(prefix_b[i-1] + (s[i-1]=='b'));
        diff.push_back(prefix_a[i] - prefix_b[i]);
    }

    map<int, int> diff_index;
    priority_queue<int> sizes;
    for(int i = 0; i < diff.size(); i++){
        if(diff_index[diff[i] - diff.back()] != 0){
            sizes.push(-1*(i+1 - diff_index[diff.back() - diff[i]]));
        }
        diff_index[diff[i]] = i+1;
    }

    if(-1*sizes.top() == n or sizes.size() == 0) cout << "-1" << endl;
    else if (diff.back() == 0) cout << "0" << endl; 
    else cout << -1*sizes.top() << endl;
    

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