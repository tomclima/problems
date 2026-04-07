/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int x, y; cin >> x >> y;
    if(x > y or ((x + y) % 2 == 0 and x == 0)){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int number_of_legs = y;
    if((x + y ) % 2) number_of_legs --;
    for(int i = 2; i <= number_of_legs+1; i++){
        cout << 1 << " " << i << endl; 
    }
    int j = 2;
    for(int i = number_of_legs+2; i<= x+y ; i++){
        cout << j << " " << i << endl;
        j++;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}