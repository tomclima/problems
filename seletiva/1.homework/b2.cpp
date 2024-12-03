#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    
    deque<string> dq;
    dq.push_back(s);

    bool abc = true;
    while(abc){
        abc = false;
        string ns;
        int i = 0;
        while(i < dq[0].size()){
            if(i + 2 < dq[0].size() and dq[0][i] == 'A' and dq[0][i+1] == 'B' and dq[0][i+2] == 'C'){
                i = i + 2;
                abc = true;
            }
            else{
                ns.push_back(dq[0][i]);
            }
            i++;
        }
        dq.push_back(ns);
        dq.pop_front();
    }

    for(int i = 0; i < dq.back().size(); i++){
        cout << dq.back()[i];
    }
}