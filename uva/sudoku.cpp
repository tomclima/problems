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
        ll n; cin >> n;

        ll sum = (n)*(n+1)/2;

        vector<ll> grids(n, 0); 
        vector<ll> lines(n, 0);
        vector<ll> columns(n, 0);

        for(int i = 0; i < n; i++){ // looping through the lines
            for(int j = 0; j < n; j++){ // looping through the columns
                ll val; cin >> val;
                columns[j]+=val;
                lines[i]+=val;
                int grid_index = floor(i/floor(sqrt(n)))*floor(sqrt(n)) + floor(j/floor(sqrt(n))); // calculate which one of the grids aij falls into
                grids[grid_index] += val;
            }
        }

        bool all_good = true;
        for(int i = 0; i < n; i++){
            all_good = all_good and (lines[i] == sum and columns[i] == sum and grids[i] == sum);
        }
        if(all_good) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}