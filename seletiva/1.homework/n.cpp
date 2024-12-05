#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

vector<bool> line;
vector<bool> r_line;
vector<vector<bool>> bs;
vector<vector<bool>> br;
vector<bool> bp;
vector<pair<int, pair<int, int>>> cmds;

void place(int i, int j){    
    pair<int, int> pos;
    pos.first = i;

    if(bp[i]){
        bs[i][j] = true;
    }
    else{
        br[i][j] = true;
    }
}

void remove(int i, int j){ 
    if(bp[i]){
        bs[i][j] = true;
    }
    else{
        br[i][j] = true;
    }
}

void reverse(int i){
    bp[i] = !bp[i];
}

void stack_push(int cmd, int i, int j){
    pair<int, int> pos;
    pos.first = i;
    pos.second = j;
    pair<int, pair<int, int>> com;
    com.first = 1;
    com.second = pos;
    cmds.push_back(com);
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;
    


    for(int i = 0; i < m; i++){
        line.push_back(0);
        r_line.push_back(1);
    }
    for(int i = 0; i < n; i++){
        bs.push_back(line);
        br.push_back(r_line);
        bp.push_back(0);
    }
    
    for(int i = 0; i < q; i++){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int i, j;
            cin >> i >> j;
            place(i, j);
            stack_push(cmd, i, j);
        }

        else if(cmd == 2){
            int i, j;
            cin >> i >> j;
            remove(i, j);
            stack_push(cmd, i, j);
        }
        else if (cmd = 3){
            int i, j;
            cin >> i;
            j = 0;
            reverse(i);
            stack_push(cmd, i, j);
        }
        else{
            int time;
            cin >> time;
            for(int j = 0; j < )

        }
        
    }



}