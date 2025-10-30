/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

ll gcd(ll a, ll b){
    if(min(a, b) == 0) return max(a, b);
    if(min(a, b) > 0) return gcd(max(a, b) - min(a, b), min(a, b));
}

ll lcm(ll a, ll b){
    return a * b/gcd(a, b);
}
