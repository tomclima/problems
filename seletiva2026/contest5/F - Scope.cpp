/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    string s; cin >> s;
    stack<char> pilha;

    map<char, bool> boxes;
    bool possible = true;
    for(auto c : s){
        if(c == ')'){
            while(pilha.top() != '('){
                boxes[pilha.top()] &= 0;
                pilha.pop();
            }
            pilha.pop();
        }
        else{
            if(c != '('){
                if(boxes[c]){
                    cout << "No" << endl;
                    return 0;
                }
                boxes[c] = 1;
            }
            pilha.push(c);
        }
    }

    cout << "Yes" << endl;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}