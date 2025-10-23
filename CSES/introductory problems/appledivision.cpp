/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

ll mindiff = 1e18;
set<ll> distinct_sums;
void chosen(vector<ll> &sums, const vector<ll> &vals, int r){
    if(r <= 0) return;

    chosen(sums, vals, r-1);
    ll original_size = sums.size();
    for(int i = 0; i < original_size; i++){
        
        ll newsum = sums[i] - vals[r-1];
        if(distinct_sums.find(newsum) == distinct_sums.end()) sums.push_back(newsum);
        distinct_sums.insert(newsum);
        if(abs(sums[0] - 2 * (newsum)) <= mindiff) mindiff = abs(sums[0] - 2 * (newsum));
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> vals;

    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll val;
        cin >> val;
        vals.push_back(val);
        sum += val;
    }

    vector<ll> sums;
    sums.push_back(sum);
    distinct_sums.insert(sum);
    chosen(sums, vals, n);

    cout << mindiff << endl;

    
}