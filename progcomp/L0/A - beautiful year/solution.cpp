#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int y;
    cin >> y;

    map <string, int> freq;

    int i = 1;
    while (true){
        int t = y+i;
        string ts = to_string(t);

        bool has_repeat = false;
        for(int i = 0; i < 4; i++){
            if(!has_repeat){
                for(int j = i+1; j < 4; j++){
                    if(ts[i] == ts[j]){
                        has_repeat = true;
                    }
                }
            }
        }

        if(has_repeat == false){
            cout << t;
            break;
        }
        i++;
    }
    return 0;
}