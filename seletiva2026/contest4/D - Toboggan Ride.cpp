/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

bool check(long double v, vector<ll> &boosts, ll len, ll time){
    long double curr_v = v;
    long double curr_t = 0;
    for(int i = 1; i < boosts.size(); i++){
        if(boosts[i-1] + curr_v*curr_v/2 < boosts[i]) return false;
        
        // bashkara
        int a = -1;
        long double b = 2*curr_v;
        long double c = -2*(boosts[i] - boosts[i-1]);
        long double delta = b*b - 4*a*c;
        
        long double dt = (-b +sqrt(delta))/(2*a);
        curr_t += dt;
        curr_v = curr_v -dt + v;
        if(curr_t > time) return false;
    }

    return true;
}

int solve(){
    ll len, n, t; cin >> len >> n >> t;
    vector<ll> boosts(n);
    for(int i = 0; i < n; i++ ){
        cin >> boosts[i];
    }

    boosts.push_back(len);
    long double l = 0;
    long double r = 1e10;
    for(int i = 0; i < 300; i++){
        long double mid = ((long double)l + r)/2;
        if(check(mid, boosts, len, t)){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout <<  setprecision(12) << fixed << l << endl;
    

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}