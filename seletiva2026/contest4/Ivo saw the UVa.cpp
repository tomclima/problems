/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define pii pair<int, int>

vector<int> dx = {1, 0, -1, 0, 1, -1, -1, 1};
vector<int> dy = {0, 1, 0, -1, 1, -1, 1, -1};

vector<string> board;
int y_len;
int x_len;

bool check_valid(pii yx){
    if(yx.first < 0 or yx.first >= y_len or yx.second < 0 or yx.second >= x_len){
        return false;
    }

    else return true;
}



int solve(){
    int n, m; cin >> n >> m;
    y_len = m; x_len = n;
    for(int i = 0; i < m; i++){
        string line; cin >> line;
        for(auto &x : line){
            x = tolower(x);
        }
        board.push_back(line);
    }

    int count_uva = 0;
    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            pii coord = {y, x};

            if(board[y][x] != 'u') continue;

            
            for(int i = 0; i < dx.size(); i++){
                string uva = "u";
                pii next_coord = {y + dy[i], x + dx[i]};
                if(check_valid(next_coord)) uva.push_back(board[next_coord.first][next_coord.second]);
                next_coord = {next_coord.first + dy[i], next_coord.second + dx[i]};
                if(check_valid(next_coord)) uva.push_back(board[next_coord.first][next_coord.second]);
                
                if(uva == "uva") count_uva++;
            }
        }
    }

    cout << count_uva;
    
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