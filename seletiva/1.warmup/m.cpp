#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> sides;
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        sides.push_back(s);
    }

    sort(sides.begin(), sides.end());

    int i = 0;
    bool possible = false;
    while(i+2 < n){
        if(sides[i+2] < sides[i] + sides[i+1]){
            possible = true;
            break;
        }
        else{
            i++;
        }
    }

    if(possible){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}