/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define ld long double
#define pll pair<ld, ld>

// TODO: solve this https://atcoder.jp/contests/dp/tasks/dp_j
/*
    dp idea: dp com estados de tres dimensões (n1, n2, n3) onde ni representa o número
    de pratos com i peças de sushi e dp(n1, n2, n3) é o custo médio de se chegar em (n1, n2, n3)
    
    a complexidade é decente O(n³), mas o maior problema é a presença de auto transições.
    se n1 + n2 + n3 = k < n, temos n - k pratos vazios, que podem cair no dado e chegar no mesmo estado
    eu gostaria de adicionar mais um parâmetro de "tamanho de caminho", mas estoura facilmente

    calma. e se so considerarmos a quantidade de pratos vazios e o número total de suhis?

    x + 2y + 3z = 3k. (m, x + y + z) é único para x, y, z >= 0 e x + y + z < n?
    x + y + z = k
    y - 2z = 2k
    y = 2(k -z)
    y <= k

    não, não identifica de forma única :((((((
    (1, 3, 0, 0) -> (1, 0, 3) -> (4, 2)
    (2, 2, 0, 0) -> (0, 2, 0) -> (4, 2)
    
    1/2 + 2/4 + 3/8 + 4/16...
    (1/2) + (1/4 + 1/4) + (1/8 + 1/8 + 1/8) + (1/16 + 1/16 + 1/16 + 1/16)...
    
    = (1/2 + 1/4 + 1/8 + ...) = 1
    + (1/4 + 1/8 + 1/16 +...) =1/2
    + (1/8 + 1/16 +...) = 1/4
    +...
    = 2

    é o "tempo" que um estado passa em uma auto transição!!!!! yipeeee

    como generalizar? ele pode ter múltiplas auto transições
    
    passo 1: calcular o tempo que passaria em uma única auto transição
    
    
    = (1/n + 1/n² + 1/n³...) = S -> 1 + S = nS -> 1 = S(n-1) -> 1/n-1 = S
    + (1/n² + 1/n³ + 1/n⁴...) = S' -> S = nS'
    + (1/n³ + 1/n⁴...)
    = n/(n-1)²

    e multiplica pelas transições
    dp(n1, n2, n3) = heheheh

*/


struct State{
    int n1, n2, n3;
    State() : n1(0), n2(0), n3(0) {};
    State(const int &n1, const int &n2, const int &n3) : n1(n1), n2(n2), n3(n3) {};
    
    bool operator<(const State &s1){
        return n1 < s1.n1;
    }
    bool operator==(const State &s) {
        return s.n1 == n1 and s.n2 == n2 and s.n3 == n3;
    }
    bool operator!=(const State &s){
        return !(operator==(s));
    }
};


pll recurse(State s, const State &s_max, map<State, pll> dp){
    if(dp.find(s) != dp.end()) return dp[s];
    if(s == s_max) return dp[s] = {0, 1};

    dp[s] = {0, 1};
    

}


int solve(){
    int n; cin >> n;
    State initial_state;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        if(a == 1) initial_state.n1++;
        else if(a == 2) initial_state.n2++;
        else if(a == 3)initial_state.n3++;
    }


    map<State, pll> dp;
    dp[initial_state] = {0, 1};
    State curr_state = initial_state;
    State final_state(0, 0, 0);
    
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