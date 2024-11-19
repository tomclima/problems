#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int y;
        int x;
        int result;
        cin >> y;
        cin >> x;

        int n = max(x, y);

        int an = 1 + ((2 * (n-1) + 2)*(n-1))/2;

        int diff = y - x;

        if(max(x, y) % 2 == 0){
            result = an- (diff);    
        }
        else{
            result = an+ diff;
        }

        cout << result << "\n";
    }
}