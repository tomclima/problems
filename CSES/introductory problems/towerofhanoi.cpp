/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define NUMBER_OF_STACKS 3;

vector<pair<int, int>> moves;

void hanoi(int n, int src , int dst){
    if (n == 1){
        moves.push_back({src, dst});
        return;
    }

    int newdst;
    for(int i = 1; i<= 3; i++) if(i != src and i!= dst) newdst = i;
    hanoi(n-1, src, newdst);
    moves.push_back({src, dst});
    hanoi(n-1, newdst, dst);

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k; cin >> k;

    hanoi(k, 1, 3);

    cout << moves.size() << endl;
    for (auto i : moves){
        cout << i.first << " " << i.second << endl;
    }

}