#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    string c;

    getline(cin, c);

    int C = stoi(c);
    
    vector<int> results;

    for(int l = 0; l < C; l++){
        string s, t;
        cin >> s;
        cin >> t;

        vector<int> w_ones;
        vector<int> w_zeros; // treat these three as stacks
        vector<int> q_ones;
        vector<int> q_zeros;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1' and s[i] != t[i]){
                w_ones.push_back(i);
            }
            else if (s[i] == '0' and s[i] != t[i]){
                w_zeros.push_back(i);
            }
            else if(s[i] == '?' and t[i] == '1'){
                q_ones.push_back(i);
            }
            else if(s[i] == '?' and t[i] == '0'){
                q_zeros.push_back(i);
            }
        }

        int moves = 0;
        bool possible = true;
        for(int i = 0; i < w_ones.size(); i++){
            if(!w_zeros.empty()){
                s.replace(w_ones[i], 1, 1, '0');
                s.replace(w_zeros.back(), 1, 1, '1');
                w_zeros.pop_back();
                moves += 1;
            }
            else if (!(q_ones.empty())){
                s.replace(w_ones[i], 1, 1, '0');
                s.replace(q_ones.back(), 1, 1, '1');
                q_ones.pop_back();
                moves += 2;
            }
        }

        for(int i = 0; i < w_zeros.size(); i++){
            s.replace(w_zeros[i], 1, 1, '1');
            moves++;
        }
        for(int i = 0; i < q_zeros.size(); i++){
            s.replace(q_zeros[i], 1, 1, '0');
            moves++;
        }
        for(int i = 0; i < q_ones.size(); i++){
            s.replace(q_ones[i], 1, 1, '1');
            moves++;
        }

        if(s != t){
            moves = -1;
        }

        results.push_back(moves);
    }

    for(int i = 0; i < results.size(); i++){
        cout << "Case " << i+1 << ": " << results[i] << endl;
    }
}