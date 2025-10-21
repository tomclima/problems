/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

void i_swap(string &str, int i, int j){
    if(i < 0 or i >= str.length() or j < 0 or j >= str.length()) throw invalid_argument("str index out of range");
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

void permute(vector<string> &perms, int r){
    if(r <= 0) return;

    permute(perms, r-1);
    ll original_size = perms.size();
    for(int i = 0; i < original_size; i++){
        for(int j = 0; j < r-1; j++){
            i_swap(perms[i], j, r);
            perms.push_back(perms[i]);
            i_swap(perms[i], r, j);
        }   
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a; cin >> a;

    vector<string> perms;
    perms.push_back(a);
    permute(perms, a.size());

    for (auto str : perms) cout << str << endl;



}