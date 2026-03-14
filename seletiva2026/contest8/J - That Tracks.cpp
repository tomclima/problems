/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


vector<string> symbols =
{
    "V...", ">...", "^...", "<...", "V.V.", ">.V.", "^.V.", "<.V.", "V.>.",
    ">.>.", "^.>.", "<.>.", "V.^.", ">.^.", "^.^.", "<.^.", "V.<.", ">.<.",
    "^.<.", "<.<.", "VV..", "V>..", "V^..", "V<..", ">V..", ">>..", ">^..",
    "><..", "^V..", "^>..", "^^..", "^<..", "<V..", "<>..", "<^..", "<<.."
 };

string trans = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int solVe(map<string, string> dict){
    int n; cin >> n;
    string s1, s2; cin >> s1 >> s2;
    string translation;
    for(int i = 0; i < s1.size(); i+=2){
        string to_trans = s1.substr(i, 2) + s2.substr(i, 2);
        translation.append(dict[to_trans]);
    }
    cout << translation << endl;
    return 0;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<string, string> dict;
    for(int i = 0; i < symbols.size(); i++){
        dict[symbols[i]] = trans[i];
    }

    int t = 1; // cin >> t;
    while(t--){
        solVe(dict);
    }
}