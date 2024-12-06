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
        lng n;
        multiset<lng> s;
        auto midi = s.end();
        lng midv = 10000000000;
        do{
            cin >> n;
            if(n > 0){
                if(s.empty()){
                    s.insert(n);
                    midi.operator--();
                    midv = *midi;
                }
                else if(n < midv and s.size() % 2 != 0){
                    s.insert(n);
                    midi.operator--();
                    midv = *midi;
                }
                else if(n < midv){
                    s.insert(n);
                }
                else if(n > midv and s.size() % 2 != 0){
                    s.insert(n);
                }
                else if(n > midv){
                    s.insert(n);
                    midi.operator++();
                    midv = *midi;
                }
            }
            else if(n < 0){
                lng rv;
                auto removed = midi;
                rv = *removed;
                if(s.size() % 2 == 0){
                    midi.operator++();
                    midv = *midi;
                    s.erase(removed);
                }
                else if (s.size() > 1){
                    midi.operator--();
                    midv = *midi;
                    s.erase(removed);
                }
                else{
                    s.erase(removed);
                    midi = s.end();
                    midv = 10000000000;
                }
                cout << rv << endl;
            }
        }while(n != 0);
    }
}