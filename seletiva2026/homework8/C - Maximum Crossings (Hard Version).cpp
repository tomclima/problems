/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000



struct Node{
    int l;
    int r;
    ll inv;

    Node(){
        l = 0;
        r = 0;
        inv =0;
    }

    Node(int left, int right, ll inversions = 0){
        l = left;
        r = right;
        inv = inversions;
    }
};


Node join(Node a, Node b, vector<int> &arr){
    ll total_inversions = a.inv + b.inv;
    sort(arr.begin() + a.l, arr.begin() + a.r +1);
    sort(arr.begin() + b.l, arr.begin() + b.r + 1);

    int b_pointer = b.l;
    ll inv = 0;
    for(int a_pointer = a.l; a_pointer <= a.r; a_pointer++){
        while(b_pointer <= b.r and arr[b_pointer] <= arr[a_pointer]){
            inv++;
            b_pointer++;
        }
        total_inversions += inv;
    }

    sort(arr.begin() + a.l, arr.begin() + b.r + 1);

    return Node(a.l, b.r, total_inversions);

}

void build(int l, int r, int idx, vector<int> &arr, vector<Node> &seg){
    
    if(l == r){
        seg[idx] = Node(l, r, 0);
        return;
    }

    int mid = (l + r)/2;

    int lc = 2*idx+1;
    int rc = 2*idx+2;

    build(l, mid, lc, arr, seg);
    build(mid+1, r, rc, arr, seg);

    seg[idx] = join(seg[lc], seg[rc], arr);
}




int solve(){
    
    int n; cin >> n;
    vector<int> arr(n);
    vector<Node> seg(4*n);

    for(auto &i : arr) cin >> i;

    build(0, n-1, 0, arr, seg);

    cout << seg[0].inv << endl;
    

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen(usaco.in, "r", stdin); freopen(usaco.out, "w", stdout);

    int t = 1; cin >> t;
    while(t--){
        solve();
    }
}