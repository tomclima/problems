#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

#define endl "\n";

typedef struct avl_node {
    int key;
    int height;
    struct avl_node *right;
    struct avl_node *left;
} avl_node;

avl_node *avl_createnode(int key){
    avl_node *node = (avl_node*)malloc(sizeof(avl_node) * 1);
    node->key = key;
    node->right = NULL;
    node->left = NULL;
    node->height = 0;

    return node;
}

int avl_getheight(avl_node *rt){
    if(!rt){return -1;}
    else{return rt->height;}
}

int avl_getbalance(avl_node *rt){
    if(!rt){return 0;}
    else{
        return (avl_getheight(rt->left) - avl_getheight(rt->right));
    }
}

typedef struct avl_tree {
    avl_node *root;
    int nodecount;
} avl_tree;

avl_tree *avl_createtree(){
    avl_tree *tree = (avl_tree*)malloc(sizeof(avl_tree*) * 1);
    tree->root = NULL;
    tree->nodecount = 0;

    return tree;
}

avl_node *avl_rightrotate(avl_node *rt){
    avl_node *l = rt->left;
    avl_node *lr = l->right;
    l->right = rt;
    rt->left = lr;
    rt->height = 1 + max(avl_getheight(rt->right), avl_getheight(rt->left));
    l->height = 1 + max(avl_getheight(l->right), avl_getheight(l->left));
    return l;
}

avl_node *avl_leftrotate(avl_node *rt){
    avl_node *r = rt->right;
    avl_node *rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = 1 + max(avl_getheight(rt->right), avl_getheight(rt->left));
    r->height = 1 + max(avl_getheight(r->right), avl_getheight(r->left));
    return r;
}

avl_node *avl_inserthelp(avl_node *rt, int key){
    if(!rt){return avl_createnode(key);}
    if(rt->key > key){rt->left = avl_inserthelp(rt->left, key);}
    else{rt->right = avl_inserthelp(rt->right, key);}

    rt->height = 1 + max(avl_getheight(rt->right), avl_getheight(rt->left));
    int balance = avl_getbalance(rt);

    if(balance < -1 && key >= rt->right->key){return avl_leftrotate(rt);}
    if(balance > 1 && key < rt->left->key){return avl_rightrotate(rt);}
    if(balance > 1 && key >= rt->left->key){
        rt->left = avl_leftrotate(rt->left);
        return avl_rightrotate(rt);
    }
    if(balance < -1 && key < rt->right->key){
        rt->right = avl_rightrotate(rt->right);
        return avl_leftrotate(rt);
    } 
    return rt;
}

void avl_insert(avl_tree *tree, int key){
    tree->root = avl_inserthelp(tree->root, key);
    tree->nodecount++;
}

avl_node *avl_removehelp(avl_node *rt, int key){
    
    return rt;
}

void avl_remove(avl_tree *tree, int key){
    tree ->root = avl_removehelp(tree->root, key);
    tree->nodecount--;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;
    for(int k = 0; k < t; k++){
        avl_tree *bst = avl_createtree();
        int n = 1;
        while(n != 0){
            cin >> n;
            cout << n;
            if(n > 0){
                avl_insert(bst, n);
            }
            else{
                cout << bst->root->key << endl;
                avl_remove(bst, bst->root->key);
            }
        }
    }
}