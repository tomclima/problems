/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    string pat;
    cin >> s >> pat;

    int d =  5;
    int q = 1e9+7;

    int n = s.length();
    int m = pat.length();

    int c = 1;
    for(int i = 0; i < m -1; i++){
        c = c * d % q;
    }
    int p = 0;
    int t = 0;
    for(int i = 0; i < m-1; i++){
        p = (p * d + pat[i]) % q;
        t = (t * d + s[i]) % q;
    }
    

}