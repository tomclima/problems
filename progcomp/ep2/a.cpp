#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int
#define ZERO 0.0000001
double fun(double x, double b, double c){
    double ans = x*x + b * x + c;
    return ans/sin(x);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double pi = M_PI;
    int tc;
    cin >> tc;
    while(tc--){
        long double b, c;
        cin >> b >> c;

        double epsilon = ZERO;
        double best = -1;
        double left = ZERO;
        double right = pi/2;
        while(right - left > epsilon){
            double midl = left + (right - left)/3;
            double midr = left + 2*(right - left)/3;

            if(fun(midl, b, c) < fun(midr, b, c)){
                right = midr;
            }
            else{
                left = midl;
            }

            best = fun(left + (right - left)/2, b, c);
        }

        cout << fixed << best << setprecision(7) << endl;
    }
}