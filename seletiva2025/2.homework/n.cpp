#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

long double d(int x1, int y1, int x2, int y2){
    return sqrt((long double)(x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int px, py, ax, ay, bx, by;
        cin >> px >> py >> ax >> ay >>bx >> by;

        long double dap = d(ax, ay, px, py);
        long double dbp = d(bx, by, px, py);
        long double da0 = d(ax, ay, 0, 0);
        long double db0 = d(bx, by, 0, 0);
        
        bool a0, ap;

        long double minp, min0;
        if(da0 <= db0){
            a0 = true;
            min0 = da0;
        }
        else{
            a0 = false;
            min0 = db0;
        }
        if(dap <= dbp){
            ap = true;
            minp = dap;
        }
        else{
            ap = false;
            minp = dbp;
        }

        long double minpow = minp * (minp > min0) + min0 * (min0 >= minp);

        long double ans;
        if(2 * minpow >= d(ax, ay, bx, by) or ap == a0) ans = minpow;
        else ans = d(ax, ay, bx, by)/2;

        cout << fixed << ans << setprecision(10) << endl;

    }
}