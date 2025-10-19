// binary search
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

bool check(){

}

int main(){

    // closed interval [lo, hi]
    ll l = 0;
    ll r = 1e18;
    while (l <= r){
        ll middle = l + (r - l)/2;
        if (check()){
            r = middle-1;
        }
        else{
            l = middle+1;
        }
    }

    // half open interval [lo, hi)
    l = 0;
    r = 1e18;
    while (l < r){
        ll middle = l + (r - l)/2;
        if(check()){
            r = middle;
        }
        else{
            l = middle + 1;
        }
    }

}

