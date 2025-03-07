/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int P1 = 31;
int P2 = 37;
lng mod1 = 1000000007;
lng mod2 = 1000000009;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, bad;
    cin >> s >> bad;
    int k;
    cin >> k;

    map<char, bool> good_chars;
    for(int i = 0; i < 26; i++){
        good_chars[char('a' + i)] = (bad[i] - '0');
    }

    set<pair<lng, lng>> hashes;
    for(int i = 0; i < s.length(); i++){
        int count = 0;
        lng last_hash1 = 0;
        lng last_hash2 = 0;
        lng power1 = 1;
        lng power2 = 1;

        for(int j = i; j < s.length(); j++){
            if(!good_chars[s[j]]) count++;
            if(count > k) break;
            
            last_hash1 += (lng)((lng)(s[j] - 'a' + 1) * power1 ) % mod1;
            last_hash2 += (lng)((lng)(s[j] - 'a' + 1) * power2 ) % mod2;
            hashes.insert({last_hash1, last_hash2});
            power1 = (P1 * power1) % mod1;
            power2 = (P2 * power2) % mod2;
        }
    }

    cout << hashes.size() << endl;
}
