/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int
#define INF 99999999
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

#define p_queue queue<pair<lng, State>>

vector<int> dy = {0, 1, 0, -1};
vector<int> dx = {-1, 0, 1, 0};


typedef tuple<int, int, int, int> State;
class Custom_comp{
    public:
        bool operator()(const pair<lng, State> &a, const pair<lng, State> &b){
            return a.first > b.first;
        }
};




int next_color(int color) {return (color + 1) % N_COLORS;}

int cycle_ori(int orientation, int cycles){
    return (orientation + cycles) % N_ORIENTATIONS;
}

void relax(State a, State b, map<State, lng> &dist, p_queue &fila){
    dist[b] = dist[a] + 1;
    fila.push({dist[b], b});
    
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
            cout << endl;
        }
        
        vector<string> space;
        
        pair<int, int> S, T;
        
        
        for(int i = 0; i < m; i++){
            
            string line;
            cin >> line;
            space.push_back(line);
            
            for(int j = 0; j < n; j++) {
                
                if(space[i][j] == 'S') S = {i, j};
                else if(space[i][j] == 'T') T = {i, j};
            }
            
        }
        
        map<State, lng> dist;
        map<State, bool> visited;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < N_COLORS; k++){
                    for(int l = 0; l < N_ORIENTATIONS; l++){
                        dist[{i, j, k, l}] = INF;
                        visited[{i, j, k, l}] = false;
                    }
                }
            }
        }

        dist[{S.first, S.second, GREEN, NORTH}] = 0;
        
        p_queue fila;
        
        fila.push({0, {S.first, S.second, GREEN, NORTH}});
        while(!fila.empty()){
            

            State state = fila.front().second;
            fila.pop(); 
            if(visited[state] == true) continue;
            visited[state] = true;
            
            int x, y, color, orientation;
            x =             get<0>(state);
            y =             get<1>(state);
            color =         get<2>(state);
            orientation=    get<3>(state);

            if(x == T.first and y == T.second and color == GREEN) continue;
            
            
            
            
            int new_color = next_color(color);
            
            int new_x = x + dx[orientation];
            int new_y = y + dy[orientation];
            
            
            if(!(new_x < 0 or new_x >= space.size() or new_y < 0 or new_y >= space[0].size() or space[new_x][new_y] == '#' or visited[{new_x, new_y, new_color, orientation}])){
                relax(state, {new_x, new_y, new_color, orientation}, dist, fila);
            }

            relax(state, {x, y, color, cycle_ori(orientation, 3)}, dist, fila); // relax left
            relax(state, {x, y, color, cycle_ori(orientation, 1)}, dist, fila); //  relax right
            
        }
        
        lng ans = INF;
        for(int i = 0; i < 4; i++) ans = min(ans, dist[{T.first, T.second, GREEN, i}]);
        
        cout << "Case #" << counter << endl; 
        if(ans < INF) cout << "minimum time = " << ans << " sec" << endl;
        else cout << "destination not reachable" << endl;
        
        
    }
    
}