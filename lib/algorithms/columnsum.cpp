/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int





int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    string str; cin >> str; // this is an absurdly large number (2*10^5 digits. DO NOT TREAT IT AS A NUMBER)
    
    // get first s1 + 2s2 + 3s3 + ... 2e5s_2e5
    ll sum_units = 0;
    for(int i = 0; i < n; i++){
        sum_units += (str[i] - '0')*(i+1);
    }

    vector<int> number;
    ll original_sum = sum_units;
    ll addition = 100000;
    // column sum kind of logic. alter according to the problem
    for(int i = 0; i < n; i++){
        number.push_back(sum_units%10);
        addition = sum_units/10;
        ll removal = (n-i)*(str[n-i-1] - '0');
        original_sum -= removal;
        sum_units = original_sum + addition;
    }
    if(addition > 0){
        number.push_back(addition);
    }
    

    for(int i = number.size()-1; i >= 0; i--){
        cout << number[i];
    }

    
}