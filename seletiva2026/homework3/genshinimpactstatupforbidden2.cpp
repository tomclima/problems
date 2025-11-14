/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define SIDE_LEN 19


vector<vector<int>> graph(SIDE_LEN*SIDE_LEN);
vector<vector<int>> board(SIDE_LEN, vector<int>(SIDE_LEN, -1));


int coord_encode(pair<int, int> coord){
    return SIDE_LEN*coord.first + coord.second;
}


int get_color(int encoded_coord){
    int y = encoded_coord/SIDE_LEN;
    int x = encoded_coord % SIDE_LEN;
    return board[y][x];
}


pair<int, int> add_stone(int y, int x, int color){
    board[y][x] = color;
    int encoded = coord_encode({y, x});
    
    vector<int> visited(SIDE_LEN*SIDE_LEN);

    if(y + 1 < SIDE_LEN) {
        graph[encoded].push_back(coord_encode({y+1, x}));
        graph[coord_encode({y+1, x})].push_back(encoded);
        
    }
    if(y-1 >= 0) {
        graph[encoded].push_back(coord_encode({y-1, x}));
        graph[coord_encode({y-1, x})].push_back(encoded);

    }
    if(x + 1 < SIDE_LEN){
        graph[encoded].push_back(coord_encode({y, x+1}));
        graph[coord_encode({y, x+1})].push_back(encoded);
 

    } 
    if(x-1 >= 0) {
        graph[encoded].push_back(coord_encode({y, x-1}));
        graph[coord_encode({y, x-1})].push_back(encoded);

    }

    pair<int, int> playerinfo = get_groupinfo(coord_encode({y, x}), color, visited);
    vector<pair<int, int>> enemy_infos;
    if(y + 1 < SIDE_LEN) {
        enemy_infos.push_back(get_groupinfo(coord_encode({y+1, x}), !color, visited));
    }
    if(y-1 >= 0) {
        enemy_infos.push_back(get_groupinfo(coord_encode({y-1, x}), !color, visited));
    }
    if(x + 1 < SIDE_LEN){
        enemy_infos.push_back(get_groupinfo(coord_encode({y, x+1}), !color, visited));

    } 
    if(x-1 >= 0) {
        enemy_infos.push_back(get_groupinfo(coord_encode({y, x-1}), !color, visited));
    }

    int player_destroyed = playerinfo.second * (playerinfo.first == 0);
    int enemy_destroyed = 0;
    for(int i = 0; i < 4; i++){
        enemy_destroyed+= enemy_infos[i].second * (enemy_infos[i].first == 0);
    }


    return {player_destroyed, enemy_destroyed};
}

pair<int, int> get_groupinfo(int root, int color, vector<int> visited){ // returb {liberties, groupsize}

    int group_size = 0;
    set<int> group_liberties;
    stack<int> queue;

    visited[root] = true;
    queue.push(root);
    group_size++;
    if(get_color(root) != color) return {0, 0};

    while(!queue.empty()){
        int u = queue.top(); queue.pop();
        
        for(int i: graph[u]){
            
            if(visited[i]){
                continue;
            }

            int color_i = get_color(i);
            if(color_i == 0){
                visited[i] = true;
                group_liberties.insert(i);                
            }
            else if(color_i == color){
                visited[i] = true;
                queue.push(i);
                group_size++;
            }

        }
    }

    for(auto liberty : group_liberties){
        visited[liberty] = false;
    }

    int liberties = group_liberties.size();

    return {liberties, group_size};
}

int solve(){
    int n; cin >> n;
    

    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;

        pair<int, int> player_enemy = add_stone(a-1, b-1, i%2);

        if(i %2 == 0){
            cout << player_enemy.first << " " << player_enemy.second;
        }
        else{
            cout << player_enemy.second << " " << player_enemy.first;
        }


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