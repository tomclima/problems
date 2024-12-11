#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    for(int tc; tc < q; tc++){
        lng k;
        cin >> k;
        lng i = 0;
        while(k - 9 * 10 * i >= 0){
            k -= 9 * 10 * i;
            i++;
        }
        lng quotient = k / (i + 1);
        lng remainder = k % (i + 1);
        lng number = 9 * 10 * i + quotient * (i+1);
    }
}