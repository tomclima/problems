#include <bits/stdc++.h>


int count = 0;

bool safe_diagonal(std :: vector<std :: string> &board, std :: pair<int, int> &atk, std :: pair<int, int> &def){
    
    bool answer = true;
    int dy = abs(atk.first - def.first);
    int dx = abs(atk.second - def.second);
    if(dy == dx){
        answer = false;
    }

    return answer;
}

bool safe(std :: vector<std :: string> &board, std :: vector<std :: pair<int,int>> &qvec, int qn){
    bool answer = true;
    bool asterisk = false;
    std :: pair<int, int> qpos = qvec[qn];
    

    if(board[qvec[qn].first][qvec[qn].second] == '*'){
        answer = false;
    }  
    

    for(int i = 0; i < qn; i++){
        if(qvec[i].first == qpos.first){
            answer = false;
        }
        else if(qvec[i].second == qpos.second){
            answer = false;
        }
        else if(!safe_diagonal(board, qvec[i], qpos)){
            answer = false;
        }
        if(answer == false){
            break;
        }
    }

    return answer;
}

void eight_safe(std :: vector<std :: string> &board, std :: vector<std :: pair<int, int>> &qvec, int qn){

    while(qvec[qn].second < board.size()){
        if(safe(board, qvec, qn)){
            if(qn == 7){
                count += 1;
            }
        
            else{
                qvec[qn+1].first = qvec[qn].first + 1;
                qvec[qn+1].second = 0;
                eight_safe(board, qvec, qn+1);
            }
        }
        
        qvec[qn].second++;   
    }
    return;
    }


int main(){
    std :: ios_base::sync_with_stdio(false);

    std :: vector<std :: string> board;
    std :: vector<std :: pair<int, int>> qvec;

    for(int i = 0; i < 8; i ++){
        std :: string line;
        std :: cin >> line;
        board.push_back(line);
    }

    for(int i = 0; i < 8; i++){
        std :: pair<int, int> q;
        q.first = 0;
        q.second = 0;
        qvec.push_back(q);
    }

    
    eight_safe(board, qvec, 0);

    std :: cout << count << std :: endl;


}