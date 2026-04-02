/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define ld long double
#define pll pair<ld, ld>

int solve(){
    int n; cin >> n;
    vector<pll> tasks(n);

    for(int i = 0; i <n; i++){
        int a, b; cin >> a >> b;
        pll task = {a, b};
        tasks[i] = task;
    }

    reverse(tasks.begin(), tasks.end());
    ld ans = 0;
    for(auto task : tasks){
        ans = max(ans, task.first + ans*(1 - task.second/100));
    }

    cout << setprecision(12) << fixed << ans << endl;
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