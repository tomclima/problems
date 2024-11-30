#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    vector<string> strs;
    int count = 0;
    for(int i = 1; i <= 12; i++){
        string str;
        cin >> str;
        if(str.length() == i){
            count++;
        }
    }

    cout << count;
}