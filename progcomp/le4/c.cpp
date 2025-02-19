#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

lng sumdiv(int a){
    lng sum = 0;
    for(lng i = 1; i * i <= a; i++){
        if(a % i == 0){
            sum += i;
            if(i != a /i) sum += a/i;
        }
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int s = -1;
    int counter = 1;
    while(s != 0){
        cin >> s;
        if(s == 0) break;
        int yay;
        bool possible = 0;
        for(int i = 0; i <= s; i++){
            if(sumdiv(i) == s){
                yay = i;
                possible = true;
                if(possible and i > yay) yay = i;
            }
        }
        cout << "Case " << counter << ": ";
        if(possible) cout << yay;
        else cout << -1;
        counter++;
        cout << endl; 
    }
}