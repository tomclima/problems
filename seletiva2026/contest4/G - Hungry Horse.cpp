/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    ll n, d; cin >> n >> d;
    vector<ll> pos_un(n+1, 0);
    vector<ll> time_un(n+1, 0);
    for(int i = 1; i <=n; i++){
        cin >> pos_un[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> time_un[i];
    }

    vector<pair<ll, ll>> to_sort;
    for(int i = 0; i <= n; i++){
        to_sort.push_back({pos_un[i], time_un[i]});
    }

    sort(to_sort.begin(), to_sort.end());
    vector<ll> pos;
    vector<ll> time;
    for(int i = 0; i < n+1; i++){
        pos.push_back(to_sort[i].first);
        time.push_back(to_sort[i].second);
    }


    priority_queue<ll> dishes;

    int max_qtd = 0;
    ll curr_time = 0;
    for(int i =1; i <= n; i++){
        curr_time += pos[i] - pos[i-1];
        while(curr_time > d and !dishes.empty()){
            curr_time -= dishes.top();
            dishes.pop();
        }

        if(curr_time > d) break;

        if(curr_time + time[i] <= d){
            curr_time += time[i];
            dishes.push(time[i]);
        }
        else if(!dishes.empty() and time[i] < dishes.top()){
            curr_time -= dishes.top();
            dishes.pop();
            dishes.push(time[i]);
            curr_time += time[i];
        }
        if(dishes.size() > max_qtd) max_qtd = dishes.size();
    }

    cout << max_qtd << endl;
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