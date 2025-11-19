/*vamos continuar fazendo encoding*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define pii pair<int, int>

vector<int> dx{1, 0, -1, 0};
vector<int> dy{0, 1, 0, -1};

bool check_valid(pii pos, int y_len, int x_len){
    int y = pos.first; int x = pos.second;
    if(y >= y_len or y < 0 or x>= x_len or x < 0) return 0;
    else return 1;
}


int solve(){
    int n, m; cin >> n >> m;
    vector<string> board;
    for(int i = 0; i < n; i++){
        string str; cin >> str;
        board.push_back(str);
    }

    vector<pii> goodguys;
    vector<pii> badguys;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(board[y][x] == 'G') goodguys.push_back({y, x});
            else if(board[y][x] == 'B') badguys.push_back({y, x});
        }
    }


    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            if(board[y][x] == 'B') {
                for(int i = 0; i < dx.size(); i++){
                    pair<int, int> next = {y + dy[i], x + dx[i]};
                    if(!check_valid(next, n, m)){
                        continue;
                    }
                    if(board[next.first][next.second] != 'G' and board[next.first][next.second] != 'B'){
                        board[next.first][next.second] = '#';
                    }
                }
            }
        }
    }


    


    // bfs
    queue<pii> queue;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue.push({n-1, m-1});
    visited[n-1] [m-1] =true;
    while(!queue.empty()){
        pii u = queue.front(); queue.pop();
        if(board[u.first][u.second] == '#'){
            continue;
        }

        for(int i = 0; i < dx.size(); i++){
            pair<int, int> next = {u.first + dy[i], u.second + dx[i]};
            if(!check_valid(next, n, m)){
                continue;
            }
            if(!visited[next.first][next.second] and board[next.first][next.second] != '#'){
                visited[next.first][next.second] = true;
                queue.push(next);
            }
        }

    }


    bool possible = true;
    for(pii guy : goodguys){
        possible &= visited[guy.first][guy.second];
    }
    for(pii guy : badguys){
        possible &= not visited[guy.first][guy.second];
    }

    if(possible) cout << "Yes" << endl;
    else cout << "No" << endl;

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