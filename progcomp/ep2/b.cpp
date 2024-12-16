#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int
#define ZERO 0.000000001


long double pos(long double t, pair<long double, long double> driver){
    return driver.first * t + driver.second;
}

pair<int, int> maxminf(vector<pair<long double, long double>> &drivers, long double t){
    long double max = 0;
    long double min = INFINITY;
    int maxi = -1;
    int mini = -1;

    for(int i = 0; i < drivers.size(); i++){
        if(pos(t, drivers[i]) <= min){
            min = pos(t, drivers[i]);
            mini = i;
        }
        if(pos(t, drivers[i]) >= max){
            max = pos(t, drivers[i]);
            maxi = i;
        }
    }

    return make_pair(maxi, mini);
}

long double fun(long double t, vector<pair<long double, long double>> &drivers){
    pair<int, int> maxmin = maxminf(drivers, t);
    return pos(t, drivers[maxmin.first]) - pos(t, drivers[maxmin.second]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    long double k;
    cin >> n;
    cin >> k;
    vector<pair<long double, long double>> drivers;
    for(int i = 0; i < n; i++){
        pair<long double, long double> p;
        drivers.push_back(p);   
    }
    for(int i = 0; i < n; i++){
        cin >> drivers[i].first >> drivers[i].second;
        
    }
    long double r = k;
    long double l = ZERO;
    long double epsilon = ZERO;
    long double best;
    while(r - l > epsilon){
        long double midl = l +(r - l)/3;
        long double midr = l + 2*(r - l)/3;
        if(fun(midl, drivers) < fun(midr, drivers)){
            r = midr;
        }
        else{
            l = midl;
        }

        best = midl + (midr - midl)/2;
    }
    cout  << fixed << fun(best, drivers) << setprecision(6);
}   