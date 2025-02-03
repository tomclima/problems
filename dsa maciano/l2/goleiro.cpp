#include <bits/stdc++.h>
#include <stdlib.h>
#define ERROR -101001
using namespace std;

#define endl "\n";

typedef struct avl_node {
    long long int key;
    long long int packs;
    long long int subsum;
    int height;
    struct avl_node *right;
    struct avl_node *left;
} avl_node;

avl_node *avl_createnode(long long int key, long long int packs){
    avl_node *node = (avl_node*)malloc(sizeof(avl_node) * 1);
    node->key = key;
    node->packs = packs;
    node->subsum = packs;
    node->right = NULL;
    node->left = NULL;
    node->height = 0;

    return node;
}

int avl_getheight(avl_node *rt){
    if(!rt){return -1;}
    else{return rt->height;}
}

int avl_getsubsum(avl_node *rt){
    if(!rt){
        return 0;
    }
    else {return rt->subsum;}
}

int avl_totalsum(avl_node *rt, int val){
    if(!rt){
        return 0;
    }

    if(rt->key >= val){
        return avl_totalsum(rt->left, val);
    }
    else{
        return rt->packs + avl_totalsum(rt->right, val) + avl_getsubsum(rt->left);
    }
}

int avl_getdepth(avl_node *rt, int key){
    int depth = 0;
    while(rt){
        if(rt->key > key){
            rt = rt->left;
        }
        else if(rt->key < key){
            rt = rt-> right;
        }
        else if(rt->key == key){
            return depth;
        }
        depth++;
    }
    return ERROR;
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
    rt->subsum = rt->packs + avl_getsubsum(rt->left) + avl_getsubsum(rt->right);
    l->subsum = l->packs + avl_getsubsum(l->left) + avl_getsubsum(l->right);
    return l;
}

avl_node *avl_leftrotate(avl_node *rt){
    avl_node *r = rt->right;
    avl_node *rl = r->left;
    r->left = rt;
    rt->right = rl;
    rt->height = 1 + max(avl_getheight(rt->right), avl_getheight(rt->left));
    r->height = 1 + max(avl_getheight(r->right), avl_getheight(r->left));
    rt->subsum = rt->packs + avl_getsubsum(rt->left) + avl_getsubsum(rt->right);
    rt->subsum = r->packs + avl_getsubsum(r->left) + avl_getsubsum(r->right);
    return r;
}

avl_node *avl_inserthelp(avl_node *rt, long long int key, long long int packs){
    if(!rt){return avl_createnode(key, packs);}
    if(rt->key > key){rt->left = avl_inserthelp(rt->left, key, packs);}
    else{rt->right = avl_inserthelp(rt->right, key, packs);}

    rt->height = 1 + max(avl_getheight(rt->right), avl_getheight(rt->left));
    rt->subsum = rt->packs + avl_getsubsum(rt->left) + avl_getsubsum(rt->right);
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

void avl_insert(avl_tree *tree, long long int key, long long int packs){
    tree->root = avl_inserthelp(tree->root, key, packs);
    tree->nodecount++;
}

void avl_preorder(avl_node *rt){
    if(rt){
        cout << rt->key << " ";
        avl_preorder(rt->left);
        avl_preorder(rt->right);
    }
}

avl_node *findhelp(avl_node *rt, int key){
    if(rt == NULL){
        return NULL;
    }
    else if(rt->key > key){
        return findhelp(rt->left, key);
    }
    else if(rt->key < key){
        return findhelp(rt->right , key);
    }
    else{
        return rt;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    avl_tree *avl = avl_createtree();
    string cmd = "";
    long long int curr = 0;
    while(cmd != "END"){
        cin >> cmd;
        if(cmd == "ADD"){
            long long int id, packs;
            cin >> id >> packs;
            curr += packs;
            avl_insert(avl, id, packs);
            cout << curr << endl;
        }
        else if(cmd == "WEI"){
            long long int id;
            cin >> id;
            avl_node *node = findhelp(avl->root, id);
            int depth = avl_getdepth(avl->root, id);
            if(depth == ERROR){
                cout << "0 -1" << endl;
            }
            else{
                cout << node->packs << " " << depth << endl;
            }
        }
        else if(cmd == "RNK"){
            int val;
            cin >> val;
            long long int total = avl_totalsum(avl->root, val);
            cout << total << endl;
        }
    }
    avl_preorder(avl->root);
}