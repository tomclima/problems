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
        string n;
        cin >> n;
        int threes = 0;
        int twos = 0;
        int sum = 0;
        for(int i = 0; i < n.length(); i++){
            if(n[i] == 3){
                threes++;
            }
            else if(n[i] == 2){
                twos++;
            }
            sum += n[i];
        }
        int modulo = 9 - sum % 9
    }
}