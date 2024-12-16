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
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
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
    return min(leftsum, rightsum);
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
        tree[node] = min(tree[2 *node + 1], tree[2 *node + 2]);
    }
}

int main(){

}