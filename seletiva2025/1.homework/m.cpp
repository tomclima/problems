#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int n, m, L;
        cin >> n >> m >> L;
        vector<pair<lng, lng>> hurdles;
        vector<pair<lng, lng>> powers;
        priority_queue<lng> heap;
        vector<int> events;
        for(int i = 0; i < n; i++){
            int l, r;
            cin >> l >> r;
            pair<lng, lng> h;
            hurdles.push_back(make_pair(l, r));
            events.push_back(l);
        }
        for(int i = 0; i < m; i++){
            int p, v;
            cin >> p >> v;
            powers.push_back(make_pair(p, v));
            events.push_back(p);
        }

        sort(events.begin(), events.end());

        int jump = 1;
        int cnt = 0;
        int pi = 0;
        int hi = 0;
        bool possible = true;
        for(int i = 0; i < events.size(); i++){
            if(pi < powers.size() and events[i] == powers[pi].first){
                heap.push(powers[pi].second);
                pi++;
            }
            else if(hi < hurdles.size()){
                while(!heap.empty() and (hurdles[hi].second - hurdles[hi].first + 1) >= jump){
                    jump += heap.top();
                    heap.pop();
                    cnt++;
                }
                if(hurdles[hi].second - hurdles[hi].first + 1 >= jump){
                    possible = false;
                    i = events.size();
                }
                hi++;
            }
        }

        if(!possible){
            cnt = -1;
        }
        cout << cnt << endl;
    }
}
