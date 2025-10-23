/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    vector<int> prefix_w;
    prefix_w.push_back(0);
    for(int i = 1; i <= s.length(); i++){
        prefix_w.push_back(prefix_w[i-1] + (s[i-1] == 'v' and (i - 2 >= 0 and s[i-2] == 'v')));
    }
    
    ll count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'o'){
            ll left = prefix_w[i] - prefix_w[0]; // number of w's on the left of o 
            ll right = prefix_w.back() - prefix_w[i]; // number of w's on the right of o
            count += left*right;
        } 
    }
    

    cout << count;
}