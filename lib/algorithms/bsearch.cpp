// binary search
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

bool check(){

}

int main(){

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

}

