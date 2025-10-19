#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

bool check(const vector<ll> &mach, const ll time, const ll toys){
    ll sum = 0;
    for (int i = 0; i < mach.size(); i++){
        sum += time/(mach[i]);
        if (sum >= toys) return true;
    }
    if (sum >= toys) return true;
    return false;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; ll t;
    cin >> n >> t;

    // machines initialization
    vector<ll> mach;
    for(int i = 0; i < n; i++){
        ll w;
        cin >> w;
        mach.push_back(w);
    }

    // binary search
    ll l = 0;
    ll r = 1e18;
    while (l <= r){
        ll middle = l + (r - l)/2;
        if (check(mach, middle, t)){
            r = middle-1;
        }
        else{
            l = middle+1;
        }
    }

    cout << l << endl;


}