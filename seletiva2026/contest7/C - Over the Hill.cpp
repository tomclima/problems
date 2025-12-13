/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int char_encode(char chr){
    if(isalpha(chr)) return chr - 'A';
    if(isalnum(chr)) return 26 + chr - '0';
    return 36;
}

char int_decode(int val){
    if(val < 26) return 'A' + val;
    if(val < 36) return '0' + (val-26);
    else return ' ';
}

int vec_dot(vector<int> v1, vector<int> v2){
    int dot = 0;
    for(int i = 0; i < v1.size(); i++){
        dot += v1[i]*v2[i];
    }

    return dot;
}

int solve(){
    int n; cin >> n;
    vector<vector<int>> matrix(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int val; cin >> val;
            matrix[i].push_back(val);
        }
    }

    string plaintext;
    string portion;
    while(cin >> portion){
        plaintext += portion + ' ';
    }
    plaintext.pop_back();

    int remainder = plaintext.size() % n;
    remainder = abs(n - remainder);
    if(remainder == n) remainder = 0;
    
    for(int i = 0; i < remainder; i++){
        plaintext += ' ';
    }

    vector<vector<int>> encoded_groups;
    for(int i = 0; i < plaintext.size(); i+=n){
        vector<int> encoded;
        for(int j = 0; j < n; j++){
            encoded.push_back(char_encode(plaintext[i+j]));
        }
        encoded_groups.push_back(encoded);
    }

    vector<int> encrypted_chars;
    for(auto v : encoded_groups){
        for(auto line : matrix){
            encrypted_chars.push_back(vec_dot(v, line) % 37);
        }
    }

    string ans;

    for(auto c : encrypted_chars){
        ans += int_decode(c);
    }

    cout << ans;



    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}