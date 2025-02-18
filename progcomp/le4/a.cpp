#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    lng k = 0;
    lng i = 1;
    while(n >= i * i){
        k += (n - i * i)/i + 1;
        i++;
    }
    cout << k << endl;
}