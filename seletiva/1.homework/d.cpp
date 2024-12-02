#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    string s;
    
    cin >> n >> q;
    cin >> s;
    s.push_back('A');
    vector<lng> prefix;
    lng cnt = 0;
    for(int i = 0; i < n; i++){
        prefix.push_back(cnt);
        if(s[i] == s[i+1]){
            cnt++;
        }
    }
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        cout << prefix[r-1] - prefix[l-1] << endl;
    }
}