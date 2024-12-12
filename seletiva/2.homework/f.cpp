#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

bool check(string s, int k){
    multiset<char> ms;
    bool possible = true;
    for(int i = 0; i < min(k, (int)s.length()); i++){
        ms.insert(s[i]);
    }
    for(int i = 1; i + k < s.length(); i++){
        if(!ms.empty() and ms.find(s[i + k -1]) != ms.end()){
            ms.insert(s[i + k - 1 ]);
        }
        if(!ms.empty() and ms.find(s[i-1]) != ms.end()){

            ms.erase(ms.find(s[i-1]));
        }
    }

    if(ms.empty()){
        possible = false;
    }
    return possible;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int l = 1;
    int r = s.length();
    int answer = -1;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(!check(s, mid )){
            l = mid +1;
        }
        else{
            answer = mid;
            r = mid -1;
        }
    }
    if(answer == -1){
        answer = l + (r - l)/2;
    }

    cout << answer;
}