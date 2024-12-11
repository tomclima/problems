#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lng n, m;
    cin >> n >> m;
    set<pair<lng, lng>> danger;
    for(int i = 0; i < m; i++){
        pair<lng, lng> pos;
        cin >> pos.first >> pos.second;
        pos.first -= 1;
        pos.second -= 1;
        danger.insert(pos);
        vector<pair<lng,lng>> squares;
        squares.push_back(make_pair(pos.first + 2, pos.second+1));
        squares.push_back(make_pair(pos.first + 1, pos.second+2));
        squares.push_back(make_pair(pos.first + -1, pos.second+2));
        squares.push_back(make_pair(pos.first + 2, pos.second-1));
        squares.push_back(make_pair(pos.first - 2, pos.second-1));
        squares.push_back(make_pair(pos.first - 1, pos.second -2));
        squares.push_back(make_pair(pos.first - 2, pos.second+1));
        squares.push_back(make_pair(pos.first + 1, pos.second-2));
        for(int i = 0; i < squares.size(); i++){
            if(squares[i].first >= 0 and squares[i].first < n and squares[i].second >= 0 and squares[i].second < n){
                danger.insert(squares[i]);
            }
        }
    }
    lng safe = n * n - danger.size();
    cout << n * n - danger.size();
}
