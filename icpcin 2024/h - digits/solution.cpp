#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string xo;

    do{
        cin >> xo;

        if(xo != "END"){
            int steps = 1;
            int n = xo.size();
            do{
                string digits = to_string(n);
                n = digits.size();
                steps++;
            }while(n > 1);
            cout << steps << endl;  
        }

    }while(xo != "END");
}