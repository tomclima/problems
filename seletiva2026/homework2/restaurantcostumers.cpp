/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int



int solve(){
    int n; cin >> n;
    vector<ll> events;
    vector<pair<ll , ll>> times;
    for(int i = 0; i < n; i++){
        int x, y; cin >>x  >> y;
        events.push_back(x);
        events.push_back(y);
        times.push_back({x, y});
    }

    sort(events.begin(), events.end());
    sort(times.begin(), times.end());
    events.erase(unique(events.begin(), events.end()), events.end());
    vector<ll> sweepline(events.size()+1, 0);
    for(int i = 0; i < n; i++){
        int pos1 = lower_bound(events.begin(), events.end(), times[i].first) - events.begin();
        int pos2 = lower_bound(events.begin(), events.end(), times[i].second) - events.begin();
        sweepline[pos1]++;
        sweepline[pos2]--;
    }

    vector<ll> prefix(sweepline.size()+1, 0);
    ll max = -1e18;
    int i_max = -1;
    for(int i = 1; i <= sweepline.size(); i++){
        prefix[i] = prefix[i-1] + sweepline[i-1];
        if(prefix[i] > max) {
            i_max = i;
            max = prefix[i];
        }
    }

    cout << max << endl;
    return 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}