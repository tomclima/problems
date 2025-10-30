/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int solve(){

    int n; cin >> n;
    vector<string> strings;
    int min_length = 1e18;
    string min_suffix;
    int min_count = 0;
    for(int i = 0; i < n; i++){
        string str ; cin >> str;
        strings.push_back(str);
        if(str.length() < min_length){
            min_count = 1;
            min_length = str.length();
            min_suffix = str;
        }
        else if(str.length() == min_length){
            min_count++;
        }
    }

    bool possible = true;
    if(min_count > 1){
        possible = false;
    }
    
    for (auto str : strings){
        if( !possible or str.substr(str.size() - min_length, str.size()) != min_suffix){
            possible = false;
            break;
        }
    }

    if(possible){
        cout << min_suffix << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
}