/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int



int solve(){
    int n, m; cin >> n>> m;
    vector<pair<int, int>> roads;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        if(a < b){
            roads.push_back({a-1, b-1});
        }
        else{
            roads.push_back({b-1, a-1});
        }
    }

    vector<vector<bool>> inside_blocks(n, vector<bool> (n, false));
    vector<vector<bool>> outside_blocks(n, vector<bool> (n, false));

    string ans;
    for(int i = 0; i < m; i++){
        ans.push_back('a');
    }

    bool possible = true;

    vector<int> visited(m);
    stack<int> queue; 
    queue.push(0);
    visited[0] = true;
    while(!queue.empty() and possible){
        int k = queue.top();
        pair<int, int> u = roads[queue.top()]; queue.pop();

        int a = u.first; int b = u.second;

        if(!inside_blocks[a][b]){
            ans[k] = 'i';
            for(int i = a+1; i < b; i++){
                for(int j = 0; j < n; j++){
                    if(j < a or j > b){
                        inside_blocks[i][j] = true;
                        inside_blocks[j][i] = true;
                    }
                }
            }
        }
        else if(!outside_blocks[a][b]){
            ans[k] = 'o';
            for(int i = a+1; i < b; i++){
                for(int j = 0; j < n; j++){
                    if(j < a or j > b){
                        outside_blocks[i][j] = true;
                        outside_blocks[j][i] = true;
                    }
                }
            }
        }
        else possible = false;

        int max_count = 0;
        int index = -1;
        for(int i = 0; i < m; i++){
            if(visited[i]) continue;

            int a = roads[i].first;
            int b = roads[i].second;

            int curr = inside_blocks[a][b] + outside_blocks[a][b];
            if(curr >= max_count){
                index = i;
                max_count = curr;
            }
        }
        if(index != -1){
            visited[index] = true;
            queue.push(index);
        }
    }

    if(!possible) cout << "Impossible";
    else cout << ans;

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