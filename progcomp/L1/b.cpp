#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long

lng int fun(lng int x, lng int d){
    lng int teto = ceil((long double)(d)/(x+1));
    return x + teto;
}
int main(){
    ios_base::sync_with_stdio(false);

    lng int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        lng int n, d;
        cin >> n >> d;

        lng int left = 0;
        lng int right = n;
        bool possible = false;
        while(left < right and not possible){
            lng int midl = left + (right - left)/3;
            lng int midr = right - (right - left)/3;

            if(n >= fun(midl, d) or n >= fun(midr, d)){
                possible = true;
            }        
            else if(fun(midl,d) > n and fun(midr, d) > n){
                left = midl + 1;
                right = midr - 1;
            }
        }        
        if(possible){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
