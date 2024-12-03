#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;   

    int n = s.size();

    map<int, int> jumps;
    map<int, int> prev;
    prev.insert(make_pair(0, 0));
    for(int i = 0; i < n; i++){
        jumps.insert(make_pair(i, i+1));
        prev.insert(make_pair(i+1, i));
    }
    int i = 0;
    while(i + 2 < n){
        bool abc = false;
        if(s[i] == 'A' and s[jumps[i]] == 'B' and s[jumps[jumps[i]]] == 'C'){
            jumps[prev[i]] = jumps[jumps[jumps[i]]];
            prev[jumps[jumps[jumps[i]]]] = prev[i];
            abc = true;
        }
        if(i > 0 and abc){
            i = prev[prev[i]];
        }
        i = jumps[i];
    }

    int j = 0;
    while(j < n){
        cout << s[j];
        j = jumps[j];
    }
    
}