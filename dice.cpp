#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    
    cin >> n;

    int answer = 1;
    int removals = 0;
    answer = pow(2, n-1);

    if(n > 6){
        int removals = 1;
        for(int i = 0; i < n-6; i++){
            removals = 2*removals + pow(2, i);
        }
    }

    answer -= removals;

    long long int modulo = pow(10, 9) + 7;
    cout << answer % modulo;
}