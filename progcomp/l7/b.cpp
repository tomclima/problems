/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 999999999
#define lng long long int
#define p_queue priority_queue<pair<State, lng>, vector<pair<State, lng>>, Custom_comp>

typedef tuple<int, int, int> State;


vector<int> dn1 =       {-3, -3, +2, +2};
vector<int> dn5 =       {-1, +1, -2, +0};
vector<int> dn10 =      {+0, -1, +0, -1};

vector<int> w_vec =     {+4, +4, +2, +1};


lng cost[150][100][150];

lng solve(State origin, int n1, int c_max){
    
    int n5 = get<0>(origin);
    int n10 = get<1>(origin);
    int c = get<2>(origin);

    if(c >= c_max) return cost[n5][n10][c] = 0;
    if(cost[n5][n10][c] > -1) return cost[n5][n10][c];
    
    
    if(n5 == 0 and n10 == 0) return (c_max - c)*8;
    int new_c = c + 1;
    
    lng q = INF;
    for(int i = 0; i < 4; i++){
        
        int new_n1 = n1 + dn1[i];
        int new_n5 = n5 + dn5[i];
        int new_n10 = n10 + dn10[i];
        int w = w_vec[i];

        if(new_n1 >= 0 and new_n5 >= 0 and new_n10 >= 0){
            State trans = {new_n5, new_n10, new_c};
            q = min(q, w + solve(trans, new_n1, c_max));
        }
    }

    cost[n5][n10][c] = q;

    return cost[n5][n10][c];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        
        int c, n1, n5, n10;
        cin >> c >> n1 >> n5 >> n10;
        
        memset(cost, -1, sizeof(cost));
        
        State origin = {n5, n10, 0};
        int total_money = n1 + 5*n5 + 10*n10;

        int a = solve(origin, total_money, c);

        cout << a << endl;
    }   
}
