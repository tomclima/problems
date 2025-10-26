/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    string substr;

    cin >> s >> substr;

    bool possible = false;
    for(int i = 0; i <= s.size() - substr.size(); i++){
        for(int j = 0; j < substr.size(); j++){
            if(!(s[i+j] == substr[j] or s[i+j] =='?')) break; 
            if(j == substr.size() - 1) possible = true;
        }   
    }

    if(possible) cout << "Yes" << endl;
    else cout << "No" << endl;
}