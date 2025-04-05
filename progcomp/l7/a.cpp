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

int next_color(int color) {return (color + 1) % N_COLORS;}

vector<vector<vector<State>>> dp;

bool operator>(const vector<int> &a, const vector<int> &b){
    if(dp[a[0]][a[1]][a[2]].min_time < dp[b[0]][b[1]][b[2]].min_time) return true;
    return false;
}

vector<int> colors = {GREEN, WHITE, BLUE, RED, BLACK};
State ERROR;

State min_time(vector<string> &space, vector<vector<vector<bool>>> &visited, int x_origin, int y_origin, int color_origin){

    priority_queue<vector<int>> heap;

    heap.push({x_origin, y_origin, color_origin});

    for(int i = 0; i < space[0].size() * space.size(); i++){
        
        vector<int> a;
        int x;
        int y;
        int color;
        do{
            
            if(heap.empty()) return;
            a = heap.top();
            heap.pop();

        } while(visited[a[0]][a[1]][a[2]]); 
        
        visited[a[0]][a[1]][a[2]] = true;
        
        if(x > 0 and !visited[x -1][y][next_color(color)] and dp[x -1][y][next_color(color)] > ){ // going NORTH

            
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
        
        vector<string> space;

        pair<int, int> S, T;
        
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
        int ans = min_time(space, visited, T.first, T.second, GREEN).min_time;
        

        cout << "Case #" << counter << endl; 
        if(ans < INF) cout << "minimum time =" << ans << " sec";
        else cout << "destination not reachable";
        cout << endl << endl;
        
        
    }

}