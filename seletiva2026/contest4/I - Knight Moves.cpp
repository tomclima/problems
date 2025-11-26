/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define pii pair<int, int>


vector<int> dy{-2, -2, -1, -1, +2, +2, +1, +1};
vector<int> dx{+1, -1, -2, +2, +1, -1, -2, +2};
int y_len = 8;
int x_len = 8;

pii decode_coord(string square){
    int y = square[1] - '1';
    int x = square[0] - 'a';
    return {y, x};
}

bool check_valid(pii yx){
    if(yx.first < 0 or yx.first >=y_len or yx.second < 0 or yx.second >=x_len){
        return false;
    }
    return true;
}

int bfs(pii ori, pii dest, vector<vector<int>> &dist){
    queue<pii> queue;
    queue.push(ori);
    dist[ori.first][ori.second] = 0;
    
    while(!queue.empty()){
        pii u = queue.front(); queue.pop();

        for(int i = 0; i < dx.size(); i++){
            pii next = {u.first + dy[i], u.second + dx[i]};

            if (check_valid(next) and dist[next.first][next.second] == -1){
                queue.push(next);
                dist[next.first][next.second] = dist[u.first][u.second] + 1;
            }
        }
    }

    return dist[dest.first][dest.second];

}

int solve(){
    string ori_str, dest_str;
    while(cin >> ori_str >> dest_str){
        pii ori = decode_coord(ori_str);
        pii dest = decode_coord(dest_str);

        vector<vector<int>> dist(8, vector<int> (8, -1));
        int distance = bfs(ori, dest, dist);
        cout << "To get from " << ori_str << " to " << dest_str <<  " takes " << distance <<  " knight moves." << endl;

        

    }
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