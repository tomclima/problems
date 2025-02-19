#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

lng gcd(lng a, lng b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int> unsorted;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            unsorted.push_back(x);
        }

        int common = 0;
        for(int i = 0; i < n; i++){
            int distance = abs(i + 1 - unsorted[i]) ;
            common = gcd(common, distance);
        }

        cout << common << endl;


        
    }


}