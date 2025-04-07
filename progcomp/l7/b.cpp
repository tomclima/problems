/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 999999999
#define lng long long int
#define p_queue priority_queue<pair<State, lng>, vector<pair<State, lng>>, Custom_comp>

typedef tuple<int, int, int> State;


vector<int> dn10 = {-1, -1, 0, 0, 0};
vector<int> dn5 = {0, 0, -2, -1, 0};


lng cost[101][51][151];

lng solve(State origin, lng total_money, int c_max){
    
    int n5 = get<0>(origin);
    int n10 = get<1>(origin);
    int c = get<2>(origin);
    int ch = get<3>(origin);
    
    int n1 = total_money - 8*c - 5*n5 - 10*n10 + ch * 2;

    if(cost[n5][n10][c] > -1) return cost[n5][n10][c];
    if(c >= c_max) return cost[n5][n10][c] = 0;

    
    int new_c = get<2>(origin) + 1;
    
    lng q = INF;
    

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
