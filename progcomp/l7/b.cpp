/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 999999999
#define lng long long int
#define p_queue priority_queue<pair<State, lng>, vector<pair<State, lng>>, Custom_comp>

typedef tuple<int, int, int, bool> State;

class cmap {
    private:
        std::map<State, lng> myMap;
    public:
        lng& operator[](State key) {
            if (myMap.find(key) == myMap.end()) {
                myMap[key] = INF;  // Custom default value
            }
            return myMap[key];
        }
    };

class Custom_comp{
    public:
        bool operator()(const pair<State, lng> &a, const pair<State, lng> &b){
            return a.second > b.second;
        }
};

bool get_mark(State state, set<State> visited){
    if(visited.find(state) != visited.end()) return true;
    else return false;

}

void relax(State a, State b, int w, cmap &cost, p_queue &heap){
    if(cost[a] > cost[b] + w){
        cost[a] = cost[b] + w;
        heap.push({b, cost[b]});
    }
}

vector<int> dn1 =   {-8, -3, -3, +2, +2};
vector<int> dn5 =   {0, -1, 0, -2, 0};
vector<int> dn10 =  {0, 0, -1, 0, -1};
vector<int> w_vec = {8, 4, 4, 2, 1};
vector<bool> change_v = {0, 0, 0, 1, 1};

lng solve(State origin, lng total_money, vector<vector<vector<vector<lng>>>> &dp, int c_max){
    
    int n5 = get<0>(origin);
    int n10 = get<1>(origin);
    int c = get<2>(origin);
    int ch = get<3>(origin);

    if(dp[n5][n10][c][ch] < INF) return dp[n5][n10][c][ch];
    if(get<2>(origin) >= c_max) return 0;

    dp[n5][n10][c][ch] = INF;

    int new_c = get<2>(origin) + 1;

    int n1 = total_money - 8*c - 5*n5 - 10*n10 + ch * 2;
    
    lng q = dp[n5][n10][c][ch];
    for(int i = 0; i < 5; i++){
        
        int new_n1 = n1 + dn1[i];
        int new_n5 = get<0>(origin) + dn5[i];
        int new_n10 = get<1>(origin) + dn10[i];
        int w = w_vec[i];


        if(new_n1 >= 0 and new_n5 >= 0 and new_n10 >= 0){
            State trans = {new_n5, new_n10, new_c, change_v[i]};
            q = min(q, w + solve(trans, total_money, dp, c_max));
        }
    }

    dp[n5][n10][c][ch] = q;

    return dp[n5][n10][c][ch];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        
        int c, n1, n5, n10;
        cin >> c >> n1 >> n5 >> n10;
        
        vector<vector<vector<vector<lng>>>> cost(101, vector<vector<vector<lng>>>(51, vector<vector<lng>>(151, vector<lng>(2, INF))));
        
        State origin = {n5, n10, 0, false};
        int total_money = n1 + 5*n5 + 10*n10;

        int a = solve(origin, total_money, cost, c);

        cout << a << endl;
    }   


}