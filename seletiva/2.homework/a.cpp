#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    lng n, x;
    cin >> n >> x;
    set<lng> s;
    map<lng, int> pos;
    int answer1, answer2;
    bool possible = false;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        lng target = x - a;
        if(s.find(target) != s.end()){
            possible = true;
            answer1 = i;
            answer2 = pos[target];
        }
        s.insert(a);
        pos[a] = i;
    }


    if (possible){
        cout << answer1 +1  << " " << answer2 + 1;
    } 
    else{
        cout << "IMPOSSIBLE";
    }

    
    
}