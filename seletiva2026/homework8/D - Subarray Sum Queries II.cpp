/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

ll INF = (ll)MAXN;


struct Node{
    ll max_sum;
    ll max_prefix_sum;
    ll max_suffix_sum;
    ll total_sum;

    
    Node(ll max_prefix, ll max_suffix = 0, ll max_s = 0, ll total=0){
        max_sum = max_s;
        max_prefix_sum = max_prefix;
        max_suffix_sum = max_suffix;
        total_sum = total;
    }
    Node(){
        max_suffix_sum = 0;
        max_prefix_sum = 0;
        max_sum = 0;
        total_sum = 0;
    }
};



Node neutral_element(){
    return Node(0, 0, 0, 0);
}


Node join(Node left, Node right){
    
    ll max_whole = max(left.max_sum, right.max_sum);
    
    ll intersection = left.max_suffix_sum + right.max_prefix_sum;

    Node newnode;
    // getting the value for the node
    ll total_sum = left.total_sum + right.total_sum;

    ll max_sum = max(max_whole, intersection);

    ll max_prefix = max(left.total_sum + right.max_prefix_sum, left.max_prefix_sum);

    ll max_suffix = max(right.max_suffix_sum, right.total_sum + left.max_suffix_sum);

    newnode.max_prefix_sum = max(max_prefix, (ll)0);
    newnode.max_suffix_sum = max(max_suffix, (ll)0);
    newnode.max_sum = max(max_sum, (ll)0);
    newnode.total_sum = total_sum;

    return newnode;

}


Node query(int L, int R, int l, int r, int idx, vector<Node> &seg){
    
    if(l > R or r < L) return neutral_element();

    if(l >= L and r <= R) return seg[idx];

    int mid = (l + r)/2;

    int lc = 2*idx+1;
    int rc = 2*idx+2;

    Node left_query = query(L, R, l, mid, lc, seg);
    Node right_query = query(L, R, mid+1, r, rc, seg);

    Node query_ans = join(left_query, right_query);

    return query_ans;
}

void build(int l, int r, int idx, vector<int> &arr, vector<Node> &seg){
    
    if(l == r){

        Node newnode;
        newnode.max_prefix_sum = max(arr[l], 0);
        newnode.max_suffix_sum = max(arr[l], 0);
        newnode.max_sum = max(arr[l], 0);
        newnode.total_sum = arr[l];
        seg[idx] = newnode;
        return;
    }

    int mid = (l + r)/2;

    int lc = 2*idx+1;
    int rc = 2*idx+2;

    build(l, mid, lc, arr, seg);
    build(mid+1, r, rc, arr, seg);

    seg[idx] = join(seg[lc], seg[rc]);
}



int solve(){
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    vector<Node> seg(4*n);
    
    for(auto &i : arr) cin >> i;
    build(0, n-1, 0, arr, seg);

    while(q--){
        
        int a, b; cin >> a >> b;

        cout << query(a-1, b-1, 0, n-1, 0, seg).max_sum << endl;
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