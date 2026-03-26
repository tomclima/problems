/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<ll, ll>
#define pll pair<long double, long double>

long double dist(pll p1, pll p2){
    long double dx = p1.first - p2.first;
    long double dy = p1.second - p2.second;
    return sqrt(dy*dy + dx*dx);

}

long double max_dist(pll p, vector<pii> &cows, vector<ll> radi){
    long double best=0;
    for(int i = 0; i < cows.size(); i++){
        best = max(best, dist(p, cows[i]) - radi[i]);
    }
    return best;
}

long double check(long double mid, vector<pii> &cows, vector<ll> &radi){
    long double l = -1000;
    long double r = 1000;
    int iterations = 50;
    while(iterations--){
        long double midl = l + (r -l)/3;
        long double midr = r - (r - l)/3;
        if(max_dist({mid, midl}, cows, radi) < max_dist({mid, midr}, cows, radi)){
            r  = midr;
        }
        else{
            l = midl;
        }
    }

    return l;
}


int bcheck(long double time, pll p, vector<pii> &cows, vector<ll> &radi){
    bool has_intersection = true;
    for(int i = 0; i < cows.size(); i++){
        if(dist(p, cows[i]) > time + radi[i]){
            return false;
        }
    }

    return true;
}

int solve(){
    int n; cin >> n;
    vector<pii> cows(n);
    vector<ll> radi(n);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        cows[i] = {x, y};
        cin >> radi[i];
    }

    long double l = (long double)-1000;
    long double r = (long double)1000;
    int iterations = 50;

    while(l < r and iterations--){
        
        long double midl = l + (r - l)/3;
        long double midr = r - (r - l)/3;
        if(max_dist({midl, check(midl, cows, radi)}, cows, radi) < max_dist({midr, check(midr, cows, radi)}, cows, radi)){
            r = midr;
        }
        else{
            l = midl;
        }    
    }

    pll best_point = {l, check(l, cows, radi)};



    long double bl = 0;
    long double br = 4000;
    iterations = 50;
    while(bl < br and iterations--){
        long double mid = (bl + br)/2;
        if(bcheck(mid, best_point,cows, radi)){
            br = mid;
        }
        else{
            bl = mid;
        }
    }

    cout << setprecision(8) << fixed << bl;


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