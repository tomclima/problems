/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int teams, total, limit; cin >> teams >> total >> limit;

    map<int, int> school_teams;
    vector<pair<int, int>> repescagem;
    vector<pair<int, int>> passed;
    for(int i = 0; i < teams; i++){
        int id, school; cin >> id >> school;
        if(school_teams[school] >= limit){
            repescagem.push_back({i, id});
        }
        else if(total > 0){
            passed.push_back({i, id});
            school_teams[school] += 1;
            total--;
        }
    }

    if(total == 0){
        for(int i = 0; i < passed.size(); i++){
            cout << passed[i].second << endl;
        }
        return 0;
    }

    for(int i = 0; i < min(total, (int)repescagem.size()); i++){
        passed.push_back(repescagem[i]);
    }   

    sort(passed.begin(), passed.end());
    
        for(int i = 0; i < passed.size(); i++){
        cout << passed[i].second << endl;
    }
    return 0;

    

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