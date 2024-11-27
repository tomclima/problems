#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    for(int l = 0; l < t; l++){
        long long int n;
        long long int a;
        cin >> n;
        string answer = "NO";

        long long int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a;
            sum += a;
        }

        long long int b = round(sqrt(sum));

        if(b * b == sum){
            answer = "YES";
        }


        cout << answer << endl;
    }


}