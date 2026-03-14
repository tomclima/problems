/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int


int dsu_find(map<int, int> &dsu, int n){
    if(dsu[n] == n) return n;

    return dsu[n] = dsu_find(dsu, dsu[n]);

}


int solve(){
    int n; cin >> n;

    map<int, int> rep_numbers;
    map<int, int> rep_people;

    vector<vector<int>> connections;
    vector<vector<int>> graph(n);
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        vector<int> favs(m);
        rep_people[i] = i;

        for (int j = 0; j < m; j++) cin >> favs[j];
        for(auto fav : favs){
            if(rep_numbers.find(fav) != rep_numbers.end() and rep_people[rep_numbers[fav]] != rep_people[i]){

 
                rep_people[i] = dsu_find(rep_numbers, rep_numbers[fav]);


                connections.push_back({i, rep_numbers[fav], fav});
                graph[i].push_back(rep_numbers[fav]);
                graph[rep_numbers[fav]].push_back(i);
            }
            else{
                rep_numbers[fav] = i;
            }
        }
    }


    
    vector<int> visited(n);
    visited[0] = true;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto u : graph[v]){
            if(!visited[u]){
                visited[u] = true;
                q.push(u);
            }
        }
    }

    for(auto b : visited){
        if(!b){
            cout << "impossible";
            return 0;
        }
    }


    

    for (auto c : connections){
        cout << c[0] +1 << " " << c[1] +1 << " " << c[2] << endl;
    }

    
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