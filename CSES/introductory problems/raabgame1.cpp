/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

vector<pair<int, int>> plays;


bool backtrack(set<int> &cards_a, set<int> &cards_b, const int rem_a,const  int rem_b){
    if(rem_a < 0 ) return false;
    if(rem_b < 0) return false;
    if(rem_a + rem_b > cards_a.size()) return false;    
    if(rem_a == 0 and rem_b == 0 and cards_a.size() == 0){
        return true;
    }

    bool possible = false;
    for(auto card_a: cards_a){
        set<int> newcardsa(cards_a);
        newcardsa.erase(card_a);
        for(auto card_b : cards_b){
            set<int> newcardsb(cards_b);
            newcardsb.erase(card_b);
            possible = backtrack(newcardsa, newcardsb, rem_a - (card_a > card_b), rem_b - (card_b > card_a));
            if(possible) {
                plays.push_back({card_a, card_b});
                return true;
            }

        }
    }
    
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, a, b; cin >> n >> a >> b;
        set<int> cards_a, cards_b;
        for(int i = 1; i <= n; i++) {cards_a.insert(i), cards_b.insert(i);}
        bool possible =backtrack(cards_a, cards_b, a, b);
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