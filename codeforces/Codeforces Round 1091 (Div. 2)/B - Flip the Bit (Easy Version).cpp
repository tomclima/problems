/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n, l, k; cin >> n >> l;
    vector<int> a(n);
    for(auto &i : a) cin >> i;

    cin >>k;
    int i = k-1;
    int j = k-1;
    int curr = a[k-1];
    int p = curr;
    int cnt = 0;
    bool found_diff = false;
    while(i >= 0 or j <n){
        while(i >= 0 and a[i] == curr){
            i--;
        }
        if(i >= 0) found_diff = true;
        while(j < n  and a[j] == curr){
            j++;
        }
        if(j < n) found_diff = true;
        if(found_diff){
            curr = !curr;
            cnt++;
        }
        i--;
        j++;
        found_diff = false;
    }

    if (curr != p) cnt++;
    cout << cnt << endl;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}