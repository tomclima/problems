#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

lng power(int zeroes){
    lng val = 1;
    for(int i = 0; i < zeroes; i++){
        val *= 2;
    }
    return val;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        int zeroes = 0;
        int ones = 0;
        while(n--){
            int num;
            cin >> num;
            if(num == 0) zeroes++;
            else if(num == 1) ones++;
        }
        lng sum = power(zeroes) * ones;

        cout << sum << endl;
    }
}