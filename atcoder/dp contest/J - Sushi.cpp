/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define ld long double
#define pll pair<ld, ld>

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

    power series errada :(((( 

    the notes are part of the statement

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
    
    bool operator<(const State &s) const {
        if(n1 != s.n1) return n1 < s.n1;
        if(n2 != s.n2) return n2 < s.n2;
        return n3 < s.n3;
    }
    bool operator==(const State &s) {
        return s.n1 == n1 and s.n2 == n2 and s.n3 == n3;
    }
    bool operator!=(const State &s){
        return !(operator==(s));
    }

    int sum_plates() const{
        return n1 + n2 + n3;
    }

    int sum_sushi() const{
        return n1 + 2*n2 + 3*n3;
    }
};


pll get_dp(State s, vector<vector<vector<pll>>> &dp){
    return dp[s.n1][s.n2][s.n3];
}

pll set_dp(State s, pll p, vector<vector<vector<pll>>> &dp){
    return dp[s.n1][s.n2][s.n3] = p;
}

pll recurse(State s, const State &s_max, vector<vector<vector<pll>>> &dp){
    
    if(s.n1 < 0 or s.n2 < 0 or s.n3 < 0) return {0, 0};
    if(s.sum_sushi() > s_max.sum_sushi() or s.sum_plates() > s_max.sum_plates()) return {0, 0};
    if(get_dp(s, dp) != make_pair((ld)0, (ld)0)) return get_dp(s, dp);


    ld n = max(s.sum_plates(), 1);
    ld n_max = s_max.sum_plates(); 
    ld expected = n_max/n;
    if(s.sum_plates() == 0) expected = 0;    

    
    set_dp(s, {expected, 0}, dp);
    State p1, p2, p3;
    p1 = s; p2 = s; p3 = s;
    p1.n1++;
    p2.n1--; p2.n2++;
    p3.n2--; p3.n3++;
    
    int i = 1;

    ld added_throws = 0;
    ld chance = 0;
    for(auto state : {p1, p2, p3}){
        int n = state.sum_plates();
        
        pll state_dp = recurse(state, s_max, dp);
        if(state_dp.second <= 0){
            i++;
            continue;
        } 
        if(i == 1){
            added_throws += state_dp.first*state_dp.second*(state.n1)/n;
            chance += state_dp.second*(state.n1)/n;
        }
        else if(i == 2){
            added_throws += state_dp.first*state_dp.second*(state.n2)/n;
            chance += state_dp.second*(state.n2)/n;
        }
        else{
            added_throws += state_dp.first*state_dp.second*(state.n3)/n;
            chance += state_dp.second*(state.n3)/n;
        }
        i++;
    }

    if(chance == 0) return {0,0};
    added_throws /= chance;
    set_dp(s, {get_dp(s, dp).first + added_throws, chance}, dp);
    
    return get_dp(s, dp);

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


    vector<vector<vector<pll>>> dp(n+1, vector<vector<pll>> (n+1, vector<pll> (n+1, {0,0})));
    set_dp(initial_state, {1,1}, dp);

    State final_state(0, 0, 0);
    cout << setprecision(12) << fixed << recurse(final_state, initial_state, dp).first;
    
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