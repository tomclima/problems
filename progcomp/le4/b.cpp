#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<lng> line;
    vector<vector<lng>> pyramid(n);

    for(int i = 0; i < n; i++){
        lng x;
        cin >> x;
        pyramid[0].push_back(x);
    }

    // bruteforce
    for(int i = 1; i < n; i++){
        for(int j = 0; j < pyramid[i - 1].size() - 1; j++){
            pyramid[i].push_back((pyramid[i-1][j] ^ pyramid[i -1][j + 1]));
        }
    }

    cout << pyramid[n-1][0];
}