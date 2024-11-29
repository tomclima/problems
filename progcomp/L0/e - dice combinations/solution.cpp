#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    long long int answer = 1;
    long long int modulo = pow(10, 9) + 7;

    for(int i = 0; i < n -1; i++){
        answer *= 2;
        answer = answer % modulo;
    }

    long long int removals = 1;

    if(n > 6){  
        long long int power = 1;
        for(int i = 1; i < n - 6; i++){
            removals = (2*removals + power) % modulo;
            power *= 2;
            power = power % modulo;
        }

        answer -= removals;
    }
    cout << answer;



}