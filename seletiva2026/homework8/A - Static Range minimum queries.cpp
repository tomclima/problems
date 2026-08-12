#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

ll INF = (ll)MAXN;

template <typename T>
class segTree{
    public:
        vector<T> seg;
        vector<T> a;
        int n;

        segTree(vector<T> arr){
            a = arr;
            seg.resize(4*a.size());
            n = a.size();
            build_tree();
        }

        T query(int L, int R){
            return make_query(L, R);
        }

        void update(int i, T val){
            update_tree(i, val);
        }

    private:

        void update_tree(int i, T val){
            update_helper()
        }

        void update_helper(int i, T val, int l, int r, int idx){
            
            if(l == r){
                seg[idx] = val;
                return;
            }

            int mid = (l + r)/2;
            int left_child = 2*idx+1;
            int right_child = 2*idx+2;

            if(i <= mid) update_helper(i, val, l, mid, 2*idx+1);
            else update_helper(i, val, mid+1, r, right_child);

            seg[idx] = join(seg[left_child], seg[right_child]);
        }

        void build_tree(){
            build(0, n -1, 0);
        }

        T make_query(int L, int R){
            return query_helper(L, R, 0, n-1, 0);
        }

        void build(int l, int r, int idx){
            
            if(l == r){
                seg[idx] = a[l];
                return;
            }
            
            int mid = (l + r)/2;

            int left_child = 2*idx+1;
            int right_child = 2*idx+2;

            build(l, mid, left_child);
            build(mid+1, r, right_child);
            seg[idx] = join(seg[left_child], seg[right_child]);
        }

        T query_helper(int L, int R, int l, int r, int idx){
            
            if(r < L || l > R) return neutral();

            if(l >= L && r <= R) return seg[idx];

            int mid = (l + r)/2;
            int left_child = 2*idx+1;
            int right_child = 2*idx+2;

            return join(query_helper(L, R, l, mid, left_child),query_helper(L, R, mid+1, r, right_child));
        }

        T join(T a, T b){
            return min(a, b);
        }

        T neutral(){
            return INF;
        }

    };


int solve(){

    int n, q; cin >> n >> q;
    vector<ll> arr(n);
    for(auto &i : arr){
        cin >> i;
    }

    segTree<ll> seg(arr);
    while(q--){
        int a, b; cin >> a >> b;
        ll ans = seg.query(a-1, b-1);
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