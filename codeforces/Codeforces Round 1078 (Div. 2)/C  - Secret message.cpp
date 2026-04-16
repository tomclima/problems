/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000


vector<ll> get_divisors_naive(ll n){
    vector<ll> divisors;
    ll limit = floor(sqrt(n) + 1);
    for(ll i = 1; i < limit; i++){
        if(n % i == 0){
          divisors.push_back(i);  
          if(i != n/i) divisors.push_back(n/i); 
        } 
    }

    sort(divisors.begin(), divisors.end());

    return divisors;
}

int solve(){
    int n, k; cin >> n >> k;
    vector<string> a(k);
    vector<set<char>> b(n);
    for(auto &i : a) cin >> i;
    for(auto &s : a){
        for (int i = 0; i < n; i++){
            b[i].insert(s[i]);
        }
    }

    int l = 1; int r = n+1;
    vector<ll> divisors = get_divisors_naive(n);
    divisors.push_back(n);
    int curr = 1;
    vector<set<char>> ans;
    for(auto d : divisors){
        curr = d;
        ans.clear();
        for(int i = 0; i < d; i++){
            ans.push_back(b[i]);
        }

        bool possible = true;
        for(int i = d; i < n and possible; i+=d){
            for(int j = 0; j < d and possible; j++){
                set<char> buf;
                set_intersection(ans[j].begin(), ans[j].end(),b[i+j].begin(), b[i+j].end(), inserter(buf, buf.begin()));
                ans[j] = buf;
                if(buf.empty()) possible = false;
            }
        }
        if(possible) break;
    }

    

    string information = "";
    for(int i = 0; i < curr; i++){
        if(ans[i].empty()) {
            cout << a[0] << endl;
            return 0;
        }
        information += *ans[i].begin();
    }
    
    for(int i = 0; i < n/information.size(); i++){
        cout << information;
    }

    cout << endl;


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