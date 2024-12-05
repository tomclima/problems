#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        int n, m;
        cin >> n>> m;
        int total = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            string w;
            cin >> w;
            total += w.length();
            if(total <= m) cnt++;
        }

        cout << cnt << endl;
    }
}