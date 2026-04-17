/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

bool check(int k, vector<int> &a, vector<int> &a_s, set<int> &s){
    
    auto it_f = lower_bound(a_s.begin(), a_s.end(), a_s[0] +k);
    if(it_f == a_s.end()) return false;

    int second = *it_f;
    auto it_s = s.lower_bound(second);
    if(it_s == s.begin()) return true;
    it_s--;
     
    if(s.lower_bound(*it_s + k) == s.end()) return false;
    return true;
}

int solve(){
    int n; cin >> n;
    int is_inc= true;
    vector<int> a(n);
    vector<int> a_sorted;
    set<int> b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i > 0 and a[i] < a[i-1]) is_inc = false;
    }
    a_sorted = a;
    sort(a_sorted.begin(), a_sorted.end());
    for(int i = 0; i < n; i++){
        if(a[i] != a_sorted[i]) b.insert(a[i]);
    }
    int l = 1;
    int r= 1000000000+1;
    while(l < r){
        int mid = (l + r)/2;
        if(!check(mid, a, a_sorted, b)){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }

    if(!is_inc){
        cout << l-1 << endl;
    }
    else cout << -1 << endl;

    

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