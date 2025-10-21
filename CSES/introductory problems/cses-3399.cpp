/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

vector<pair<int, int>> plays;


bool backtrack(vector<int> &cards, vector<bool> &used_a, vector<bool> &used_b, const int rem_a,const  int rem_b, int rem_cards){

    if(rem_a < 0 ) return false;
    if(rem_b < 0) return false;
    if(rem_a + rem_b > rem_cards) return false;    
    if(rem_a == 0 and rem_b == 0 and rem_cards == 0){
        return true;
    }

    bool possible = false;
    for(int i = 0; i < cards.size(); i++){ // cards_a loop
        if(used_a[i]) continue;
        used_a[i] = true;
        for(int j = 0; j < cards.size(); j++){
            if(used_b[j]) continue;
            used_b[j] = true;
            possible = backtrack(cards, used_a, used_b, rem_a - (cards[i] > cards[j]), rem_b - (cards[j] > cards[i]), rem_cards-1);
            used_b[j] = false;
            cout << "a" << endl;
            if(possible) {
                plays.push_back({cards[i], cards[j]});
                return true;
            }

        }
        used_a[i] = false;
    }
        if(rem_a < 0 ) return false;

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, a, b; cin >> n >> a >> b;
        vector<int> cards;
        vector<bool> used_a(n, 0);
        vector<bool> used_b(n, 0);
        for(int i = 1; i <= n; i++) cards.push_back(i);

        bool possible =backtrack(cards, used_a, used_b, a, b, n);
        if(possible){
            cout << "YES" << endl;
            for(int i = 0; i < plays.size(); i++) cout << plays[i].first << " ";
            cout << endl;
            for(int i = 0; i < plays.size(); i++) cout << plays[i].second << " ";
            plays.resize(0);
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }


}