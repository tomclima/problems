#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    vector<string> pile;
    while(t--){
        string cmd;
        cin >> cmd;
        if(cmd == "put"){
            string s;
            cin >> s;
            pile.push_back(s);
        }
        else if(cmd == "get"){
            if(pile.empty()){
                cout << "empty" << endl;
            }
            else{
                cout << pile.back() << endl;
                pile.pop_back();
            }
        }
        else{
            bool found = false;
            for(int i = 0; i < pile.size(); i++){
                if(pile[i] == "snowcoat"){
                    pile.erase(pile.begin() + i);
                    found = true;
                    break;
                }
            }
            if(found){
                cout << "winner winner chicken dinner :)" << endl;
            }
            else{
                cout << "oopsimcold :(" << endl;
            }
        }
    }
}