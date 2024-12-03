#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int n;
        cin >> n;
        vector<int> scrs;
        vector<set<string>> words;
        for(int i = 0; i < 3; i++){
            set<string> empty;
            words.push_back(empty);
            scrs.push_back(0);
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < n; j++){
                string w;
                cin >> w;
                words[i].insert(w);
            }
        }

        for(int i = 0; i < 3; i++){
            for(auto& it : words[i]){
                int first = (i+1) % 3; int second = (i+2) % 3;
                int ins = (words[first].find(it) != words[first].end()) + (words[second].find(it) != words[second].end());
                if(ins == 0) scrs[i] += 3;
                else if(ins == 1) scrs[i] += 1;
            }
        }

        for(auto& score : scrs){
            cout << score << " ";
        }
        cout << endl;
    }
}