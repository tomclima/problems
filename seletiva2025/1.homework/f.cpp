#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lng n;
    cin >> n;
    vector<lng> pl;
    for(lng i = 0; i < n; i++){
        lng k;
        cin >> k;
        pl.push_back(k);
}


    int l = 0;
    set<lng> s;
    lng best = 0;
    for(lng r = 0; r < n; r++){
        bool is_rpt = (s.find(pl[r]) != s.end());
        while(is_rpt and pl[l] != pl[r]){
            s.erase(pl[l]);
            l++;
        }
        if(is_rpt) l++;
        if(r - l + 1 > best){
            best = r - l + 1;
        }
        s.insert(pl[r]);
    }

    cout << best;

}