#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

// node = 1, start = 0, end = arr.size() - 1
void buildsegtree(int start, int end, int node, vector<lng> &arr, vector<lng> &tree){
    if(start == end){
        tree[node] = arr[start];
    }
    else{
        int mid = (start + end)/2;
        buildsegtree(start, mid, 2 * node, arr, tree);
        buildsegtree(mid + 1, end, 2 * node +1, arr, tree);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

lng query(vector<lng> &tree, int start, int end, int node, int l, int r){
    if(l > r){
        return 0;
    }
    if(l == start and r == end){
        return tree[node];
    }
    int mid = (start + end)/2;
    lng leftsum = query(tree, start, mid, 2 * node, l, min(r, mid));
    lng rightsum = query(tree, mid + 1, end, 2 * node + 1, max(l, mid+1), r);
    return leftsum + rightsum;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;  
    vector<lng> arr;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<lng> tree;
    tree.resize(4 * n);
    buildsegtree(0, n-1, 1, arr, tree);

    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        lng answer = query(tree, 0, n-1, 1,l -1, r-1);
        cout << answer << endl;
    }
}