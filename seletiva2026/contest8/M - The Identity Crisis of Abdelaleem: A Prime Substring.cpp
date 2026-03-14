/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000



int solve(){
    string s; cin >> s;
    
    // search for 10 and 11
    bool has_prime = false;
    for(int i = 0; i < s.length()-1 and !has_prime; i++){
        if(s[i] == '1' and (s[i+1] == '0' or s[i+1] == '1')){
            has_prime = true;
            break;
        }
    }

    if (has_prime){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    

    


    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);




    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}