/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<bool> visited(n);
    int i = 0;
    while(s[i] != '1'){
        i++;
    }
    int j = (i);
    int max_count = 0;
    int curr_count = 0;
    while(!visited[j]){
        if(s[j] == '1'){
            i = j;
            visited[j] = true;
            if(curr_count > max_count) max_count = curr_count;
            curr_count = 0;
        }
        else{
            curr_count++;
        }
        j = (j + 1) %n;
    }
    if(curr_count > max_count) max_count = curr_count;

    cout << max_count << endl;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;  cin >> t;
    while(t--){
        solve();
    }
}