/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s, pat;
    cin >> s >> pat;
    int n = s.length();
    int m = pat.length();
    
    vector<int> lps;
    lps.resize(m);
    
    // lps generation
    int l = 0;
    int i = 1;
    while(i < m){
        if(pat[l] == pat[i]){
            lps[i] = l+1;
            l++;
            i++;
        }
        else if (l == 0){
            lps[i] = 0;
            i++;
        }
        else{
            l = lps[l-1];
        }
    }

    // kmp algorithm
    set<int> pos;
    i = 0;
    int j = 0;

    while(i < n){
        if(s[i] == pat[j]){
            i++;
            j++;
        }
        if(j == m){
            pos.insert(i - j);
            j = lps[j -1];
        }
        else if(i < n and s[i] != pat[j]){
            if(j == 0) i++;
            else j =lps[j - 1];
        }
    }

    
    cout << pos.size() << endl;

    

}