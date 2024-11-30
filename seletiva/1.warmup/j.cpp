#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        long long int n, f, a, b;
        cin >> n >> f >> a >> b;
        bool possible = true;

        int last = 0;
        for(int i = 0; i < n; i++){
            long long int time;
            cin >> time;

            long long int delta = a * (time - last);
            if(b >= f and delta >= f){
                possible = false;
            }
            else if(b < delta){
                f -= b;
            }
            else{
                f -= delta;
            }

            last = time;

        }

        if(possible){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
}