#include <bits/stdc++.h>
using namespace std;

bool safe_diagonal(vector<string> &bstate, pair<int, int> &atk, pair<int, int> &def){
    int b0 = atk.first - atk.second;
    int b1 = atk.first + atk.second;
    int answer = true;

    if(def.first == def.second + b0 or def.first == b1 - def.second){
        answer = false;
    }

    return answer;
}

bool safe(vector<string> &bstate, vector<pair<int,int>> &qvec, pair<int, int> qpos){
    bool answer = true;
    for(int i = 0; i < qvec.size(); i++){
        if(qvec[i].first > 0 and qvec[i].first == qpos.first){
            answer = false;
        }
        else if(qvec[i].first > 0 and qvec[i].second == qpos.second){
            answer = false;
        }
        else if(qvec[i].first > 0 and !safe_diagonal(bstate, qvec[i], qpos)){
            answer = false;
        }
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);

    vector<string> board;
    vector<pair<int, int>> qvec;

    for(int i = 0; i < 8; i ++){
        string line;
        cin >> line;
        board.push_back(line);
    }

    for(int i = 0; i < 3; i++){
        pair<int, int> q;
        q.first = -1;
        q.second = -1;
        qvec.push_back(q);
    }

    



}