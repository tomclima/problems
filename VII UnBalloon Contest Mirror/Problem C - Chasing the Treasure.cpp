#include <bits/stdc++.h>
#define endle "\n"
#define ll long long int
#define pii pair<int, int>
#define ld long double


using namespace std;

int solve(){
    int b, h, l; cin >> b >> h >> l;
    
    ld total_area = b *h;
    
    ld triangle_height = l*sqrt(3)/2;
    ld triangle_area = triangle_height * l/2;

    cout << setprecision(10) << fixed << 6*triangle_area / total_area << endl;

    return 0;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL);

    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}