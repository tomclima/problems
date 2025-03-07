/*https://iudex.io/problem/618cdff697713f00010377c8/statement*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> lab;
    lab.resize(n);
    pair<int, int> src, dst;

    for(int i = 0; i < n; i++){
        lab[i].resize(m);
        
        for(int j = 0; j < m; j++){
            cin >> lab[i][j];

            if(lab[i][j] == 2) src = make_pair(i, j);
            else if(lab[i][j] == 3) dst = make_pair(i, j);
        }
    }

    vector<vector<pair<int, int>>> parent;
    vector<vector<bool>> visited;
    visited.resize(n);
    parent.resize(n);
    for(int i = 0; i < n; i++){ 
        visited[i].resize(m);
        parent[i].resize(m);
        fill(parent[i].begin(), parent[i].end(), make_pair(-1, -1));
    }
    
    queue<pair<int, int>> bfs_q;

    bfs_q.push(src);

    pair<int, int> curr;
    while(bfs_q.empty() == false){
        curr = bfs_q.front();
        bfs_q.pop();

        if(curr.first == dst.first and curr.second == dst.second) break;


        if(curr.second + 1 < m and lab[curr.first][curr.second+1] != 1 and !visited[curr.first][curr.second+1]) {
            visited[curr.first][curr.second + 1] = 1;
            parent[curr.first][curr.second + 1] = curr;

            bfs_q.emplace(make_pair(curr.first, curr.second + 1));
        }

        if(curr.second - 1 >= 0 and lab[curr.first][curr.second-1] != 1 and !visited[curr.first][curr.second-1]) {
            visited[curr.first][curr.second - 1] = 1;
            parent[curr.first][curr.second - 1] = curr;

            bfs_q.emplace(make_pair(curr.first, curr.second -1));
        }
        
        if(curr.first + 1 < n and lab[curr.first +1][curr.second] != 1 and !visited[curr.first + 1][curr.second]) {
            visited[curr.first + 1 ][curr.second] = 1;
            parent[curr.first +1 ][curr.second] = curr;

            bfs_q.emplace(make_pair(curr.first + 1, curr.second));
        }

        if(curr.first -1 >= 0 and lab[curr.first -1][curr.second] != 1 and !visited[curr.first -1][curr.second]) {
            visited[curr.first -1 ][curr.second] = 1;
            parent[curr.first -1][curr.second] = curr;

            bfs_q.emplace(make_pair(curr.first -1, curr.second));
        }
    }

    int count = 0;
    if(parent[dst.first][dst.second].first != - 1){
        while(curr.first != src.first or curr.second != src.second){
            curr = parent[curr.first][curr.second];
            count++;
        }

    }

    if(count == 0) cout << "Labirinto Impossivel" << endl;
    else cout << count << endl;
    
}