#include <bits/stdc++.h>
using namespace std;
#define int long long int

bool abc1(string s, map<int, int> n, map<int, int> p, int i){
    return s[i] == 'A' and s[n[i]] == 'B' and s[n[n[i]]] == 'C';
}

bool abc2(string s, map<int, int> n, map<int, int> p, int i){
    return s[p[i]] == 'A' and s[i] == 'B' and s[n[i]] == 'C';
}

bool abc3(string s, map<int, int> n, map<int, int> p, int i){
    return s[p[p[i]]] == 'A' and s[p[i]] == 'B' and s[i] == 'C';
}

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

    int i = 0;
    while(i + 2 < n){
            while(i >= 0){
                bool bad_a = abc1(s, next, prev, i);
                if(bad_a){
                    next[prev[i]] = next[next[next[i]]];
                    prev[next[next[next[i]]]] = prev[i];
                }
                else{
                i = prev[i];
                break;
                }
                if(next[prev[i]])
            }
        
        i = next[i];
    }

    int j = -1;
    while(j < n){
        j = next[j];
        if(j < n){
            cout << s[j];
        }
    }
    
}