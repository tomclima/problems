/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<int, int>

int solve(){
    int n, k, p, m; cin >> n >> k >> p >> m;
    vector<int> cost(n);
    vector<int> before_p;
    int j = 0;
    int energy = m;
    int total_wins = 0;
    for(auto &i : cost) {
        cin >> i;
        if (j < p-1) before_p.push_back(i);
        j++;
    }

    sort(before_p.begin(), before_p.end());
    
    if(p <= k){ // if p is playable, play instantly
        energy -= cost[p-1];
        total_wins++;
        if(energy < 0) total_wins--;
    }
    else if(p > k){ // if p is not playable, cycle until p is reached 
        for(int i = 0; i < p-k; i++){
            energy -= before_p[i];
        }
        energy-= cost[p-1];
        total_wins++;
        if(energy < 0) total_wins--;
    }
    
    int cost_p =cost[p-1];
    cost.erase(cost.begin() + p -1); 
    sort(cost.begin(), cost.end());
    int sum_cheapest  = 0;
    for(int i = 0; i < n - k; i++){
        sum_cheapest += cost[i];
    }

    int total_sum = sum_cheapest + cost_p;
    cout << total_wins + energy/total_sum << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;  cin >> t;
    while(t--){
        solve();
    }
}