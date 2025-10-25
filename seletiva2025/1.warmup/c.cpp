#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    
    string track;
    cin >> track;
    vector<int> hurdles;

    int i = 0;
    while(i < track.length()){
        if(track[i] == '|'){
            int size = 0;
            while(track[i+1] == '-'){
                i++;
                size++;
            }   
            hurdles.push_back(size);
            i++;
        }
    }

    hurdles.pop_back();
    for(int i = 0; i < hurdles.size(); i++){
        cout << hurdles[i] << " ";
    }
}