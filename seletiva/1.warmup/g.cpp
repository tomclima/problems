#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for(int k = 0; k < t; k++){
        int n;
        cin >> n;
        string path;
        cin >> path;    

        int coins = 0;
        int i = 0;
        while(i < n){
            if(path[i] == '@'){
                coins++;
            }
            if(path[i+1] != '*'){
                i++;
            }
            else if(path[i+2] != '*'){
                i += 2;
            }
            else{
                i = n;
            }
        }
        cout << coins << endl;
    }
}