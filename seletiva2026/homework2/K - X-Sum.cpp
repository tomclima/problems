/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int n, m;

ll check_sum(int i, int j, vector<vector<int>> &board){
    ll sum = board[i][j];
    int x;
    int y;
    
    // check upper right diagonal
    x = j+1;
    y = i+1;
    while(x < m and y < n){
        sum += board[y][x];
        x++;
        y++;
    }
     
    // check upper left diagonal
    x = j-1;
    y = i+1;
    while(x >= 0 and y < n){
        sum += board[y][x];
        x--;
        y++;
    }

        
    // check lower left diagonal
    x = j-1;
    y = i-1;
    while(x >= 0 and y >= 0){
        sum += board[y][x];
        x--;
        y--;
    }


    // check lower right diagonal
    x = j+1;
    y = i-1;
    while(x < m and y >= 0){
        sum += board[y][x];
        x++;
        y--;
    }
    
    
    return sum;

}   

int solve(){
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    ll best = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            best = max(best, check_sum(i, j, board));
        }
    }

    cout << best << endl;



    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}