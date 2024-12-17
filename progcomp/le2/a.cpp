#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

void buildsegtree(int l, int r, int node, vector<int> &arr, vector<lng> &tree){
    if(l == r) tree[node] = 1 * (arr[l] == arr[l+1]);
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
    string s;
    cin >> s;
    int size = s.length();
    s.push_back('k');
    vector<int> arr;
    for(int i = 0; i < size; i++){
        if(s[i] == s[i+1]){
            arr.push_back(1);
        }
        else{
            arr.push_back(0);
        }
    }
    size = arr.size();
    int m;
    cin >> m;
    vector<lng> tree;
    tree.resize(size * 4);
    buildsegtree(0, size -1, 0, arr, tree);
    while(m--){
        int l, r;
        cin >> l >> r;
        int answer = query(tree, 0, 0, size -1,l, r);
        cout << answer << endl;

    }
}