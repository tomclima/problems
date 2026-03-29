/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n; cin >> n;
    int dump;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    for(int i = 0; i < n; i++) cin >> dump;
    


    vector<int> can_decrease(n, 1);
    int last = a[0];
    for(int i = 0; i < n; i++){
        if (i > 0 and a[i] == gcd(a[i], a[i-1])) can_decrease[i] = false;
        if(i < n-1 and gcd(a[i+1], a[i]) == a[i]) can_decrease[i] = false;
        if(i > 0 and i < n-1 and (lcm(gcd(a[i-1], a[i]), gcd(a[i], a[i+1])) == a[i])) can_decrease[i] = false;
    }
    
    int cnt = 0;
    for(auto &i : can_decrease) cnt += i;

    cout << cnt << endl;
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