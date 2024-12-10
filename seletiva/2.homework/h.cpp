#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n, q;
        cin >> n >> q;
        vector<int> c;
        while(n--){
            int a;
            cin >> a;
            c.push_back(a);
        }
        sort(c.rbegin(), c.rend());
        vector<lng> prefix;
        lng sum = 0;
        for(int i = 0; i < c.size(); i++){
            prefix.push_back(sum);
            sum += c[i];
        }
        while(q--){
            int x;
            cin >> x;
            int left = 0;
            int right = 
        }
    }
}