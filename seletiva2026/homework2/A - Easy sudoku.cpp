/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

vector<set<int>> squares(9);
vector<set<int>> lines(9);
vector<set<int>> cols(9);

vector<vector<int>> sudoku(9, vector<int>(9, 0));

bool check_valid(int i, int j, int val){
    if(lines[i].find(val) != lines[i].end()) return false;
    if(cols[j].find(val) != cols[j].end()) return false;
    int grid_index = floor(i/floor(sqrt(9)))*floor(sqrt(9)) + floor(j/floor(sqrt(9))); // calculate which one of the grids aij falls into
    if(squares[grid_index].find(val) != squares[grid_index].end()) return false;
    return true;

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

bool backtrack(int i, int j, int val){
    int grid_index = (i/3)*3 + j/3; // calculate which one of the grids aij falls into
    if(i >= 9) return true;
    if(j >= 9) return  backtrack(i+1, 0, 1);
    if(val > 9) return false;
    if(sudoku[i][j] > 0) return backtrack(i, j+1, 1);
    if (!check_valid(i, j, val)) return backtrack(i, j, val+1);
    if (check_valid(i, j, val)){
        sudoku[i][j]= val;
        lines[i].insert(val);
        cols[j].insert(val);
        squares[grid_index].insert(val);
        if (!backtrack(i, j+1, 1)){
            sudoku[i][j] = 0;
            lines[i].erase(val);
            cols[j].erase(val);
            squares[grid_index].erase(val);
            return backtrack(i, j, val+1);
        }
    }

    return true;
}

int solve(){
    

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] != 0){
                lines[i].insert(sudoku[i][j]);
                cols[j].insert(sudoku[i][j]);
                int grid_index = floor(i/floor(sqrt(9)))*floor(sqrt(9)) + floor(j/floor(sqrt(9))); // calculate which one of the grids aij falls into
                squares[grid_index].insert(sudoku[i][j]);
            }
        }
    }

    bool is_possible = backtrack(0, 0, 1);
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
        solve();
    }
}