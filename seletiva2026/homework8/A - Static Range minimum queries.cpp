#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

class segTree {
    
    public:
    
        segTree(){

        }
    
    private:
        void build(int l, int r, int index, )

}


int solve(){
    int n, q; cin >> n >> q;
    vector<ll> array;
    for(int i = 0; i < n; i++){
        ll x; cin >> x;
        array.push_back(x);
    }

    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        l--; r--;
        int ans = dnc(l, r, array);
        cout << ans << endl;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}