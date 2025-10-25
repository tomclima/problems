/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        map<char, int> freqs;
        for(int i = 0; i < 4*n; i++){
            freqs[s[i]]++;
        }

        string chrs = "ABCD";
        ll starting = 4*n;
        for(auto chr : chrs){
            starting -= max(freqs[chr] - n, 0);
        }
        starting-= freqs['?'];

        cout << starting << endl;

    }
}