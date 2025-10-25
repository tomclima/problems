#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    long long int els = 0;

    vector<string> board;

    for(int i = 0; i < n; i++){
        string line;
        cin >> line;
        board.push_back(line);
    }

    vector<int> col_n;
    vector<int> lin_n;

    for(int i = 0; i < n; i++){
        col_n.push_back(0);
        lin_n.push_back(0);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'o'){
                lin_n[j]++;
                col_n[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(col_n[i] > 1){
            for(int j = 0; j < n; j++){
                if(lin_n[j] > 1 and board[i][j] == 'o'){
                    els+= (col_n[i] -1) * (lin_n[j] -1);
                }
            }
        }
    }

    cout << els;
}