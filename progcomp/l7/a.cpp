/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int
#define INF 1000000000LL
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





int next_color(int color) {return (color + 1) % N_COLORS;}

vector<vector<vector<vector<lng>>>> dp;

struct CustomCompare {
    bool operator()(const vector<lng> &a, const vector<lng> &b){
        if(a[4] > b[4]) return true;
        return false;
    }
};



vector<int> colors = {GREEN, WHITE, BLUE, RED, BLACK};

void relax(int x1, int y1, int color1, int ori1, int x2, int y2, int color2, priority_queue<vector<lng>, vector<vector<lng>>, CustomCompare> &heap){
    if(dp[x2][y2][color2][ori1] > dp[x1][y1][color1][ori1] + 1){
        dp[x2][y2][color2][ori1] = dp[x1][y1][color1][ori1] + 1;
        heap.push({x2, y2, color2, ori1, dp[x2][y2][color2][ori1]});
    }
}

void relax_orientations(int x, int y, int color, int orientation, priority_queue<vector<lng>, vector<vector<lng>>, CustomCompare> &heap){
    
    int i;
    i = 1;
        if(dp[x][y][color][(orientation + i) % N_ORIENTATIONS] > dp[x][y][color][orientation] + 1){
            dp[x][y][color][(orientation + i) % N_ORIENTATIONS] = dp[x][y][color][orientation] + 1;
            heap.push({x, y, color, (orientation + i) % N_ORIENTATIONS, dp[x][y][color][(orientation + i) % N_ORIENTATIONS]});
        }

    i = 3;
        if(dp[x][y][color][(orientation + i) % N_ORIENTATIONS] > dp[x][y][color][orientation] + 1){
            dp[x][y][color][(orientation + i) % N_ORIENTATIONS] = dp[x][y][color][orientation] + 1;
            heap.push({x, y, color, (orientation + i) % N_ORIENTATIONS, dp[x][y][color][(orientation + i) % N_ORIENTATIONS]});
        }

}


void min_time(vector<string> &space, vector<vector<vector<vector<bool>>>> &visited, int x_origin, int y_origin, int color_origin, int orient_origin, int x_dest, int y_dest){

    priority_queue<vector<lng>, vector<vector<lng>>, CustomCompare> heap;
    
    heap.push({x_origin, y_origin, color_origin, orient_origin, 0});

    while(!heap.empty()){
        
        vector<lng> a;
        int x;
        int y;
        int color;
        int orientation;
        do{
            
            if(heap.empty()) return;
            a = heap.top();
            heap.pop();

            x = a[0]; y = a[1]; color = a[2]; orientation = a[3];

        } while(visited[x][y][color][orientation]); 
        
        visited[x][y][color][orientation] = true;
        relax_orientations(x, y, color, orientation, heap );
        int next = next_color(color);

        


        if(x == x_dest and y == y_dest and color == GREEN) return;
        if(orientation == NORTH and x > 0 and space[x - 1][y] != '#' and !visited[x-1][y][next][NORTH]){ // GOING NORTH
            relax(x, y, color, orientation, x-1, y, next, heap);
        }
        
        if( orientation ==  SOUTH and x + 1 < dp.size() and space[x + 1][y] != '#' and !visited[x+1][y][next][SOUTH]){ // GOING SOUTH
            relax(x, y, color, orientation, x+1, y, next, heap);
        }

        if(orientation == EAST and y + 1 < dp[0].size() and space[x][y + 1] != '#' and !visited[x][y+1][next][EAST]){ // GOING EAST
            relax(x, y, color, orientation, x, y+1, next, heap);
        }

        if(orientation == WEST and y > 0 and space[x][y - 1] != '#' and !visited[x][y - 1][next][WEST]){ // GOING WEST
            relax(x, y, color, orientation, x, y - 1, next, heap);
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int m , n;
    int counter = 0;
    while(cin >> m >> n){
        
        counter++;
        if(m == 0) break;
        if(counter != 1){
            cout << endl << endl;
        }
        
        vector<string> space;
        
        pair<int, int> S, T;
        
        vector<vector<vector<vector<bool>>>> visited;
        
        
        visited.resize(m);
        dp.clear();
        dp.resize(m);

        
        for(int i = 0; i < m; i++){
            
            string line;
            cin >> line;
            space.push_back(line);
            dp[i].resize(n);
            visited[i].resize(n);
            
            for(int j = 0; j < n; j++) {
                
                if(space[i][j] == 'S') S = {i, j};
                else if(space[i][j] == 'T') T = {i, j};
                
                dp[i][j].resize(N_COLORS);
                visited[i][j].resize(N_COLORS);
                for(int k = 0; k < N_COLORS; k++){

                    dp[i][j][k].resize(N_ORIENTATIONS);
                    visited[i][j][k].resize(N_ORIENTATIONS);
                    fill(dp[i][j][k].begin(), dp[i][j][k].end(), INF);
                    fill(visited[i][j][k].begin(), visited[i][j][k].end(), false);
                }
            }
            
        }
        
        dp[S.first][S.second][GREEN][NORTH] = 0;
        min_time(space, visited, S.first, S.second, GREEN, NORTH, T.first, T.second);

        lng ans = min(min(min(dp[T.first][T.second][GREEN][EAST], dp[T.first][T.second][GREEN][WEST]), dp[T.first][T.second][GREEN][SOUTH]), dp[T.first][T.second][GREEN][NORTH]);

        
        cout << "Case #" << counter << endl; 
        if(ans < INF) cout << "minimum time = " << ans << " sec";
        else cout << "destination not reachable";
        
        
    }
    
}