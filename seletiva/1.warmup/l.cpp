#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;

    cin >> n;

    int fives = 0;

    int result = n;
    while(result > 0){
        fives += result/5;
        result = result/5;
    }

    cout << fives;
}