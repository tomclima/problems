/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int
#define INF 999999
#define N_COLORS 5
#define GREEN 0
#define WHITE 1
#define BLUE 2
#define RED 3
#define BLACK 4
#define N_ORIENTATIONS 4
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

class State{
    
    public:
        lng min_time;
        char orientation;

        State(){
            min_time = INF;
            orientation = NORTH;
        }
};

vector<int> colors = {GREEN, WHITE, BLUE, RED, BLACK};
State ERROR;

State min_time(vector<string> &space, vector<vector<vector<State>>> &dp, vector<vector<vector<bool>>> &visited, int x, int y, int color){

    if(x == 1 and y == 1 and color == 1) {
        cout << "here";
    }

    if(dp[x][y][color].min_time < INF) return dp[x][y][color];
    if(visited[x][y][color]) return ERROR; 

    visited[x][y][color] = true;

    lng q = dp[x][y][color].min_time;
    int orientation = NORTH;

    if(x + 1 < dp.size() and space[x+1][y] != '#') {
        
        State recursive = min_time(space, dp, visited, x + 1, y, (N_COLORS +(color - 1) % N_COLORS) % N_COLORS);
        if(recursive.min_time + abs(NORTH - recursive.orientation) + 1 < q) {
            
            q = abs(NORTH - recursive.orientation)  + recursive.min_time + 1;
            orientation = NORTH;

        }
    }

    if(x - 1 >= 0 and space[x-1][y] != '#') {
        
        State recursive = min_time(space, dp, visited, x - 1, y, (N_COLORS +(color - 1) % N_COLORS) % N_COLORS);
        if(recursive.min_time + abs(SOUTH - recursive.orientation) + 1 < q) {
            
            q = abs(SOUTH - recursive.orientation)  + recursive.min_time + 1;
            orientation = SOUTH;

        }
    }

    if(y - 1 >= 0 and space[x][y - 1] != '#') {
        
        State recursive = min_time(space, dp, visited, x, y -1 , (N_COLORS +(color - 1) % N_COLORS) % N_COLORS);
        if(recursive.min_time + abs(EAST - recursive.orientation) + 1 < q) {
            
            q = abs(EAST - recursive.orientation)  + recursive.min_time + 1;
            orientation = EAST;

        }
    }

    if(y + 1 < dp[x].size() and space[x][y +1] != '#') {
        
        State recursive = min_time(space, dp, visited, x, y + 1  , (N_COLORS +(color - 1) % N_COLORS) % N_COLORS);
        if(recursive.min_time + abs(WEST - recursive.orientation) + 1 < q) {
            
            q = abs(WEST - recursive.orientation)  + recursive.min_time  + 1;
            orientation = WEST;

        }
    }

    visited[x][y][color] = false;
    dp[x][y][color].min_time = q;
    dp[x][y][color].orientation = orientation;

    return dp[x][y][color];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m , n;
    int counter = 0;
    while(cin >> m >> n){

        counter++;
        if(m == 0) break;
        
        vector<string> space;

        pair<int, int> S, T;
        
        vector<vector<vector<State>>> dp;
        vector<vector<vector<bool>>> visited;

        visited.resize(m);
        dp.resize(m);

        for(int i = 0; i < m; i++){

            string line;
            cin >> line;
            space.push_back(line);
            dp[i].resize(n);
            visited[i].resize(n);

            for(int j = 0; j < n; j++) {
                
                dp[i][j].resize(N_COLORS);
                fill(dp[i][j].begin(), dp[i][j].end(), ERROR);
                visited[i][j].resize(N_COLORS);
                fill(visited[i][j].begin(), visited[i][j].end(), false);

                if(space[i][j] == 'S') S = {i, j};
                else if(space[i][j] == 'T') T = {i, j};
            }

        }

        dp[S.first][S.second][GREEN].min_time = 0;
        int ans = min_time(space, dp, visited, T.first, T.second, GREEN).min_time;
        

        cout << "Case #" << counter << endl; 
        if(ans < INF) cout << "minimum time =" << ans << " sec";
        else cout << "destination not reachable";
        cout << endl << endl;
        
        
    }

}