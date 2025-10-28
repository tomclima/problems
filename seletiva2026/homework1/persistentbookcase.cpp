/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int

int solve(){

    int n, m , q; cin >> n >> m >> q;

    vector<vector<int>> bookcase(1, vector<int>(n, 0));
    vector<int> sums;
    sums.push_back(0);
    while(q--){
        int opcode; cin >> opcode;
        if(opcode == 4){
            int k; cin >> k;
            bookcase.push_back(bookcase[k]);
            sums.push_back(sums[k]);

        }

        else if(opcode == 3){
            int i; cin >> i;
            i--;
            bookcase.push_back(bookcase.back());
            bookcase[bookcase.size() - 1][i] = m - bookcase.back()[i];
            sums.push_back(sums.back() - bookcase[bookcase.size() -2 ][i] + bookcase.back()[i]);


        }
        
        
        else if(opcode == 1){
            int i, j; cin >> i >> j;
            i--; j--;
            bookcase.push_back(bookcase.back());
            bookcase.back()[i]++;
            sums.push_back(sums.back() + 1);
        }

        else if(opcode == 2){
            int i, j; cin >> i >> j;
            i--; j--;
            bookcase.push_back(bookcase.back());
            bookcase.back()[i]--;
            sums.push_back(sums.back()-1);
        }
        
        cout << sums.back() << endl;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; //cin >> t;
    while(t--){
        solve();
    }
}