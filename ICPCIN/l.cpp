/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

/*
planejamento para baixo:
- chegamos em um estado
- verificamos os filhos dele
- se todos os filhos são vitórias, ele é derrota
- se algum filho é derrota, ele é vitória
*/

bool check(vector<int> &dp, const vector<int> &transitions, const ll &stones){
    if (dp[stones] != -1) return dp[stones];

    dp[stones] = 0;
    for (int i = 0; i < transitions.size(); i++){
        if (!dp[stones] and stones - transitions[i] >= 0){
            dp[stones] = dp[stones] | !check(dp, transitions, stones - transitions[i]);
        }
        else if (dp[stones]) break;
    }

    return dp[stones];
}

void parents(vector<int> &dp, const vector<int> &transitions, const ll &stones, const ll &max_stones){
    if (stones > max_stones) return;
    if(stones != 0 and dp[stones] != -1) return;
    check(dp, transitions, stones);
    for(int i =0; i < transitions.size(); i++){
        parents(dp, transitions, stones+transitions[i], max_stones);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    
    vector<int> transitions;
    vector<int> dp(n+1, -1);
    for (int i = 0; i < m; i++){
        int play;
        cin >> play;
        transitions.push_back(play);
    }

    dp[0] = 1;

    parents(dp, transitions, 0, n);

    if (dp[n]) cout << "1" << endl;
    else cout << "2" << endl;

    

}