/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

int solve(){
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(auto &i : a) cin >> i;
    cin >> k;

    int target = a[k-1];
    int i = k-1;
    int j = k-1;
    int cnt = 0;
    while(i >= 0 or j <n){
        if(i >= 0 and a[i] == a[k-1]){
            i--;
        }
        if(j < n and a[j] == a[k-1]){
            j++;
        }
        if((a[i] != a[k-1] or i < 0) and (a[j] != a[k-1] or j >= n)){
            if(!(i-1 >= 0 and a[i-1] != a[k-1]) and !(j + 1 < n and a[j+1] != a[k-1])){
                if(i -1 >= 0 or j+1 < n){
                    cnt++;
                    a[k-1] = !a[k-1];
                    j++;
                    i--;
                }
            }
            if((a[j+1] != a[k-1])){
                j++;
            }
            if(a[i-1] != a[k-1]){
                i--;
            }
            
        }
    }

    if(a[k-1] != target) cnt++;

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
}