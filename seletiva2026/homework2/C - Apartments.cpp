/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000
#define pii pair<ll, ll>

int solve(){
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> clients(n);
    vector <ll> apartments(m);
    for(auto &i : clients) cin >> i;
    for(auto &i : apartments) cin >> i;

    sort(clients.begin(), clients.end());
    sort(apartments.begin(), apartments.end());


    int i, j; i = 0; j = 0;
    int ans = 0;
    while(i < n and j < m){
        if(clients[i] -k > apartments[j])j++;
        else if (clients[i] + k < apartments[j]) i++;
        else{
            i++;
            j++;
            ans++;
        }
    }

    cout << ans << endl;
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