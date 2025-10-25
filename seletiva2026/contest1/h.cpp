/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        ll sum = 0;
        ll operations = 0;
        bool negstring = false;
        for(int i = 0; i < n; i++){
            ll val; cin >> val;
            
            if(negstring == false and val < 0){
                negstring = true;
                operations++;
            }

            if (val > 0 and negstring == true){
                negstring = false;
            }

            sum += abs(val);
        }

        cout << sum << " " << operations << endl;
    }
}