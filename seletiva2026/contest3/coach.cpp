/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

void dfs(const vector<ll> &vec, ll max_val, ll cur_sum, const ll &min_sum, const ll &max_diff, const int &index, ll &counter){
    if(cur_sum >= min_sum){
        counter++;
    }
    for(int i = index+1; i < vec.size(); i++){
        if(max_val - vec[i] <= max_diff){
            dfs(vec, max_val, cur_sum + vec[i], min_sum, max_diff, i, counter);
        }
    }
}

int solve(){
    ll n, x, d; cin >> n >> x >> d;
    vector<ll> students;
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        students.push_back(val);
    }
    sort(students.begin(), students.end());
    reverse(students.begin(), students.end());
    
    ll counter = 0;
    for(int i = 0; i < students.size(); i++){
        dfs(students, students[i], students[i], x, d, i, counter);
    }
    cout << counter;
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