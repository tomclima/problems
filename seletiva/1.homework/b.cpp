#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;   

    int n = s.size();

    map<int, int> next;
    map<int, int> prev;
    for(int i = -1; i < n; i++){
        next.insert(make_pair(i, i+1));
        prev.insert(make_pair(i+1, i));
    }
    prev[-1] = -1;

    int i = 0;
    while(i < n){
        if(i >= 0 and s[i] == 'A' and s[next[i]] == 'B' and s[next[next[i]]] == 'C'){
            next[prev[i]] = next[next[next[i]]];
            prev[next[next[next[i]]]] = prev[i];
            i = prev[prev[i]];
        }
        else{
            i = next[i];
        }
    }

    int j = -1;
    while(j < n){
        j = next[j];
        if(j < n){
            cout << s[j];
        }
    }
    
}