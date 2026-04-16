/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<int, int>

int solve(){
    int n; cin >> n;
    string s; cin >> s ;
    vector<int> zeros;
    vector<int> ones;
    int i = 0;
    for(auto c : s){
        if(c == '0') {
            zeros.push_back(i+1);
        }
        else ones.push_back(i+1);
        i++;
    }

    set<pii> visited;
    map<pii, pair<pii, bool>> parent;
    queue<pii> q;
    q.push({n, 0});
    visited.insert({n,0});
    while(!q.empty()){
        auto [a, b] = q.front();
        q.pop();
        if (b-1 > 0 and visited.find({b-1, a+1}) == visited.end()){
            q.push({b-1, a+1});
            visited.insert({b-1, a+1});
            parent[{b-1, a+1}] = {{a, b}, 1};
        }
        if (a-1 > 0 and visited.find({b+1, a-1}) == visited.end()){
            q.push({b+1, a-1});
            visited.insert({b+1, a-1});
            parent[{b+1, a-1}] = {{a, b}, 0};
        }
    }

    if(visited.find({zeros.size(), ones.size()}) == visited.end()) cout << "-1" << endl;
    else{
        pii curr = {zeros.size(), ones.size()};
        vector<int> operations;
        while(curr != make_pair(n, 0)){
            operations.push_back(parent[curr].second);
            curr = parent[curr].first;
        }
        reverse(operations.begin(), operations.end());
        int i = 0;
        int j = 0;
        int odd = false;
        vector<int> indexes;
        for(int k = 0; k < operations.size(); k++){
            if(!odd){
                if(operations[i] == 0) {
                    indexes.push_back(zeros[i]);
                    i++;
                }
                else{
                    indexes.push_back(ones[j]);
                    j++;
                }
            }
            else{
                    if(operations[i] == 0) {
                    indexes.push_back(ones[j]);
                    i++;
                }
                else{
                    indexes.push_back(zeros[i]);
                    j++;
                }
            }
            odd = !odd;
        }
        cout << indexes.size() << endl;
        for(auto a : indexes) cout << a <<" ";
        
        if(indexes.size() > 0) cout << endl; 
    }



    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}