#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n; cin >> n;
    ll sum = (n + 1)*n/2;
    n--;
    ll incomplete = 0;
    while(n--){
        ll number; cin >> number;
        incomplete += number;
    }

    cout << sum - incomplete;

}