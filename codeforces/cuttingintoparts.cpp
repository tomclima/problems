/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;


    vector<int> lo_divisors;
    vector<int> hi_divisors;
    for(int i = 1; i <= floor(sqrt(n)); i++){
        if(i * floor(n/i) == n){
            lo_divisors.push_back(i);
            hi_divisors.push_back(n/i);
        }
    }

    int min = 1e8;
    for(int i = 0; i < lo_divisors.size(); i++){
        if(lo_divisors[i] + hi_divisors[i] < min) min = lo_divisors[i] + hi_divisors[i];
    }

    cout << min -2;
}