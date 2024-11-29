#include <bits/stdc++.h>


int count = 0;

bool safe_diagonal(std :: vector<std :: string> &bstate, std :: pair<int, int> &atk, std :: pair<int, int> &def){
    int b0 = atk.first - atk.second;
    int b1 = atk.first + atk.second;
    int answer = true;

    if(def.first == def.second + b0 or def.first == b1 - def.second){
        answer = false;
    }

    return answer;
}

bool safe(std :: vector<std :: string> &bstate, std :: vector<std :: pair<int,int>> &qvec, int qn){
    bool answer = true;

    std :: pair<int, int> qpos = qvec[qn];
    
    if(bstate[qpos.first][qpos.second] == '*'){
        answer = false;
    }

    for(int i = 0; i < qn; i++){
        if(qvec[i].first == qpos.first){
            answer = false;
        }
        else if(qvec[i].second == qpos.second){
            answer = false;
        }
        else if(!safe_diagonal(bstate, qvec[i], qpos)){
            answer = false;
        }
        if(answer == false){
            break;
        }
    }



    return answer;
}

void three_safe(std :: vector<std :: string> &board, std :: vector<std :: pair<int, int>> &qvec, int qn){
    while(qvec[qn].first < board.size()){
        while(qvec[qn].second < board.size()){
            if(safe(board, qvec, qn)){
                if(qn == 2){
                    count++;
                }
            
                else{
                    qvec[qn+1].first = qvec[qn].first + 1;
                    qvec[qn+1].second = 0;
                    three_safe(board, qvec, qn+1);
                }
            }
            qvec[qn].second++;   
        }
        qvec[qn].second = 0;
        qvec[qn].first++;
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

    for(int i = 0; i < 3; i++){
        std :: pair<int, int> q;
        q.first = 0;
        q.second = 0;
        qvec.push_back(q);
    }

    
    three_safe(board, qvec, 0);

    std :: cout << count << std :: endl;


}