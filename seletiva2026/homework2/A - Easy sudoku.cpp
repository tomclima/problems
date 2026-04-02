/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

vector<vector<int>> squares(9, vector<int>(10, 0));
vector<vector<int>> lines(9, vector<int>(10, 0));
vector<vector<int>> cols(9,vector<int>(10, 0));

vector<vector<int>> sudoku(9, vector<int>(9, 0));

int grid_index(int i, int j){
    return i/3 * 3 + j/3;
}

bool check_valid(int i, int j, int val){
    
    return (!lines[i][val] and !cols[j][val] and !squares[grid_index(i, j)][val]);

}

void print_sudoku(){
    for(int i =0; i < 9; i++){
        for(int j =0; j < 8; j++){
            cout << sudoku[i][j] << " ";
        }
        cout << sudoku[i][8];
        cout << endl;
    }
}

void clear_sudoku(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            sudoku[i][j]= 0;
        }
    }
    for(int i = 0; i < 9; i++){
        for(int val = 0; val <= 9; val++){
            lines[i][val] = 0;
            cols[i][val] = 0;
            squares[i][val] = 0;
        }
    }
}

bool backtrack(int i, int j){
    if(j >= 9) return backtrack(i+1, 0);
    if(i >= 9) return true;
    if(sudoku[i][j] != 0) return backtrack(i, j+1);
    for(int val = 1; val <= 9; val++){
        if(check_valid(i, j, val)){
            lines[i][val] = 1;
            cols[j][val] = 1;
            squares[grid_index(i, j)][val] = 1;
            sudoku[i][j] = val;
            

            if (backtrack(i, j+1)) return true;
            else{
                sudoku[i][j] = 0;
                lines[i][val] = 0;
                cols[j][val] = 0;
                squares[grid_index(i, j)][val] = 0;
            }
        }
    }
    return false;
}

int solve(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int val; cin >> val;
            sudoku[i][j] = val;
            int grid_i = grid_index(i, j);
            if(val > 0){
                lines[i][val]= 1;
                cols[j][val] = 1;
                squares[grid_i][val] = 1;
            }
        }
    }

    int is_possible = backtrack(0, 0);
    if(is_possible) print_sudoku();
    else{
        cout << "No solution" << endl;
    }
    

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        clear_sudoku();
        solve();
    }
}