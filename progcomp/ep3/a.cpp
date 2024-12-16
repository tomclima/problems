#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

void buildsegtree(int l, int r, int node, vector<lng> &arr, vector<lng> &tree){
    if(l == r) tree[node] = arr[l];
    else{
        int mid = l + (r - l)/2;
        buildsegtree(l, mid, 2 * node + 1, arr, tree);
        buildsegtree(mid+1, r, 2*node + 2, arr, tree);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

lng query(vector<lng> &tree, int node, int start, int end, int l, int r){
    if(r < start or l > end){
        return 0;
    }
    if(l <= start and r <= end){
        return tree[node];
    }
    int mid = start + (end - start)/2;

    lng leftsum = query(tree, 2 * node + 1, start, mid, l, r);
    lng rightsum = query(tree, 2 * node + 2, mid+1, end , l, r);
    return leftsum + rightsum;
}

void update(vector<lng> &tree, int node, int start, int end, int idx, lng val){
    if(start == end) {
        tree[node] = val;
    }
    else{
        int mid = start + (end - start)/2;
        if(idx <= mid){
            update(tree, 2 * node + 1, start, mid, idx, val);
        }
        else{
            update(tree, 2 *node +2, mid +1, end, idx, val);
        }
        tree[node] = tree[2 *node + 1] + tree[2 *node + 2];
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<lng> arr;
    vector<lng> tree;
    for(int i = 0; i < n; i++){
        lng x;
        cin >> x;
        arr.push_back(x);
    }
    int size = n;
    tree.resize(4 * n);
    buildsegtree(0, size -1, 0, arr, tree);
    for(int i = 0; i < q; i++){
        int cmd;
        cin >> cmd;
        if(cmd == 2){
            int a, b;
            cin >> a >>b;
            lng answer = query(tree, 0, 0, size -1, a-1, b - 1);
            cout << answer << endl;
        }
        else{
            lng k, u;
            cin >> k >> u;
            update(tree, 0, 0, size-1, k -1, u);
        }
    }
}