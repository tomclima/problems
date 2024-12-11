#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    lng n;
    cin >> n;
    string s;
    cin >> s;
    lng sum_1 = 0;
    for(int i = 0; i < n; i++){
        sum_1 += (lng)(s[i] - '0') * (i + 1);
    }

    lng sum_total = sum_1;
    for(int i = 0; i < n; i++){
        lng last = (*(s.rbegin() + i)) - '0';
        cout << last << " ";
        last *= n-i;
        cout << last << endl;
        sum_1 -= last;
       
        sum_total += pow(10, i + 1) * (sum_1);
         if(sum_total < 0){
            cout << "here" << " " << sum_total << endl;
        }
    }

    cout << sum_total;
}