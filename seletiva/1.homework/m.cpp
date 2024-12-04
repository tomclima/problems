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
        vector<pair<lng, vector<lng>>> powers;
        priority_queue<lng> heap;
        for(int i = 0; i < n; i++){
            int l, r;
            cin >> l >> r;
            pair<lng, lng> h;
            h.first = l;
            h.second = r;
            hurdles.push_back(h);
        }
        for(int i = 0; i < m; i++){
            int p, v;
            cin >> p >> v;
            if(i > 0 and p == powers[i -1].first){
                i--;
                m--;
            }
            else{
                vector<lng> vec;
                pair<lng, vector<lng>> par;
                par.first = p;
                par.second = vec;
                powers.push_back(par);
            }
            powers[i].second.push_back(v);
        }

        int jump = 1;
        int cnt = 0;
        int pi = 0;
        int hi = 0;
        bool possible = true;
        for(int i = 0; i < L; i++){
            if(hi < hurdles.size() and hurdles[hi].first == i){
                while(!heap.empty() and (hurdles[hi].second - hurdles[hi].first + 1) >= jump){
                    jump += heap.top();
                    heap.pop();
                    cnt++;
                }
                if(hurdles[hi].second - hurdles[hi].first + 1 >= jump){
                    possible = false;
                    break;
                }
                else{
                    i += hurdles[hi].second - hurdles[hi].first;
                }
                hi++;
            }
            else if(pi < powers.size() and powers[pi].first == i){
                for(int j = 0; j < powers[pi].second.size(); j++){
                    heap.push(powers[pi].second[j]);
                }
                pi++;
            }
        }
        if(!possible){
            cnt = -1;
        }
        cout << cnt << endl;
    }
}
