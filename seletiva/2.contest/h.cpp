#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        bool cor = true;
        int n;
        cin >> n;
        vector<set<int>> col;
        vector<set<int>> grid;
        int gn = -n;
        for(int i = 0; i < n; i++){
            set<int> s;
            col.push_back(s);
            grid.push_back(s);
        }
        for(int i = 0; i < n; i++){
            if(i  % (int)(float)sqrt(n) == 0){
                gn += (int)(float)sqrt(n);
            }
            for(int j = 0; j < n; j++){
                int x;
                cin >> x;
                if (col[j].find(x) != col[j].end()){
                    cor = false;
                }
                else{
                    col[j].insert(x);
                }
                if(i  % (int)(float)sqrt(n) == 0 and j % (int)(float)sqrt(n) == 0){
                    cout << "here" << endl;
                
                }
                else if(grid[gn + (int)(j/(int)(float)sqrt(n))].find(x) != grid[gn + (int)(j/(int)(float)sqrt(n))].end()){
                    cor = false;
                }
                
                grid[gn + (int)(j/(int)(float)sqrt(n))].insert(x);
                
            }
        }
        if(!cor) cout << "no" << endl;
        else cout << "yes" << endl;
    }

}