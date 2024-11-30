#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<int> votes;

    for(int i = 0; i < n; i++){
        votes.push_back(0);
    }

    int winner = 1;
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        votes[num - 1]++;
        if(votes[num -1] > votes[winner - 1]){
            winner = num;
        }
        else if(votes[num -1] == votes[winner -1] and num -1 < winner - 1){
            winner = num;
        }

        cout << winner << endl;
    }

   
}