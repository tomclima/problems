/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<int, int>

ll INF = 10000000;

vector<pii> next_square(pii pos, vector<vector<char>> &board){
    int n = board.size();
    int m = board[0].size();
    
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    vector<pii> next;
    for(int i = 0; i < dx.size(); i++){
        if (dx[i] + pos.second >= m) continue;
        else if(dx[i] + pos.second <0) continue;
        else if(dy[i] + pos.first < 0) continue;
        else if (dy[i] + pos.first >= n) continue;
        else if (board[dy[i] + pos.first][dx[i]+pos.second] == '#') continue;
        else if (board[dy[i] + pos.first][dx[i]+pos.second] == 'M') continue;
        else next.push_back({pos.first+dy[i], pos.second+dx[i]});
    }

    return next;
}

int solve(){
    int n, m; cin >> n >> m;
    vector<vector<char>> board(n, vector<char> (m, '#'));
    pii hero;
    vector<pii> monsters;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'A') hero = {i, j};
            else if(board[i][j] == 'M') monsters.push_back({i, j});
        }
    }

    // get monster distances
    vector<vector<bool>> visited_monsters(n, vector<bool>(m, 0));
    vector<vector<int>> distances_monsters(n, vector<int> (m, INF));
    queue<pii> q_monsters;

    for(auto monster :monsters){
        visited_monsters[monster.first][monster.second] = true;
        q_monsters.push(monster);
        distances_monsters[monster.first][monster.second] = 0;
    }
    vector<pii> exit_monsters;
    while(!q_monsters.empty()){
        auto v = q_monsters.front();
        q_monsters.pop();
        if(v.first == 0 or v.second == 0 or v.first == n-1 or v.second == m-1){
            exit_monsters.push_back(v);
        }

        vector<pii> next = next_square(v, board);
        for(auto u : next){
            if(!visited_monsters[u.first][u.second]){
                q_monsters.push(u);
                visited_monsters[u.first][u.second] = true;
                distances_monsters[u.first][u.second] = distances_monsters[v.first][v.second] + 1;
            }
        }
    }



    // get hero distance
    vector<vector<bool>> visited_hero(n, vector<bool>(m, 0));
    vector<vector<pii>> prev(n, vector<pii> (m, {-1, -1}));
    vector<vector<int>> distances_hero(n, vector<int> (m, INF));
    distances_hero[hero.first][hero.second] = 0;
    visited_hero[hero.first][hero.second] = 1;
    queue<pii> q_hero;
    q_hero.push(hero);
    vector<pii> exit_hero;
    while(!q_hero.empty()){
        auto v = q_hero.front();
        q_hero.pop();

        if(v.first == 0 or v.second == 0 or v.first == n-1 or v.second == m-1){
            exit_hero.push_back(v);
        }

        vector<pii> next = next_square(v, board);
        for(auto u : next){
            if(!visited_hero[u.first][u.second]){
                if(distances_hero[v.first][v.second] + 1 < distances_monsters[u.first][u.second]){
                    q_hero.push(u);
                    visited_hero[u.first][u.second] = true;
                    prev[u.first][u.second] = v;
                    distances_hero[u.first][u.second] = distances_hero[v.first][v.second] + 1;
                    
                }
 
            }
        }
    }

    pii chosen_exit = {-1, -1};
    for(auto exit : exit_hero){
        auto [a, b] = exit;
        if(distances_hero[a][b] < distances_monsters[a][b]){
            chosen_exit = exit;
        }
    }

    if(chosen_exit.first == -1){
        cout << "NO" << endl;
        return 0;
    }
    
    string path;
    pii curr_node = chosen_exit;
    while(!(board[curr_node.first][curr_node.second] == 'A')){
        auto [y, x] = curr_node;
        if(prev[y][x].first - curr_node.first > 0) path.append("U");
        else if(prev[y][x].first - curr_node.first < 0) path.append("D");
        else if(prev[y][x].second - curr_node.second > 0) path.append("L");
        else if(prev[y][x].second - curr_node.second < 0) path.append("R");
        curr_node = prev[y][x];
    }

    reverse(path.begin(), path.end());
    cout << "YES" << endl << path.length() << endl << path << endl;


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