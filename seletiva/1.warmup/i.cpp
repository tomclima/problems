#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    string wstr;
    long long int w = 0;
    long long int i = 0;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'v' and s[i+1] == 'v'){
            w++;
            wstr.push_back('w');
        }
        else if(s[i] == 'o'){
            wstr.push_back('o');
        }
    }

    vector<long long int> opos;
    for(int i = 0; i < wstr.size(); i++){
        if(wstr[i] == 'o'){
            opos.push_back(i+1);
        }
    }

    long long int wows = 0;
    for(int i = 0; i < opos.size(); i++){
        long long int left = opos[i] -1 - i;
        long long int right = wstr.size() - opos[i] - (opos.size() - i) + 1;
        wows += left * right;
    }

    cout << wows;
 
}