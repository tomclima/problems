#include <bits/stdc++.h>
#define endl '\n'
#define lng long long int

typedef struct Node{
    std :: string name;
    int key;
    struct Node *prev;
    struct Node *right;
    struct Node *left;
} Node;

Node *create_node(std ::string name, int key){
    Node *newnode = new Node;
    newnode->key = key;
    newnode->name = name;
    newnode->prev = NULL;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

typedef struct Bst{
    Node *rt;
    int size;
} Bst;

Bst *create_bst(){
    Bst *newbst = new Bst;
    newbst->rt = NULL;
    newbst->size = 0;
    return newbst;
}

Node *find(Node *rt, int key){
    Node *searchnode = rt;
    while(searchnode != NULL and searchnode->key != key){
        if(rt->key > key){
            searchnode = searchnode->left;
        }
        else{
            searchnode = searchnode->right;
        }
    }

    return searchnode;  
}

void insert()




void insert(Bst *bst){

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);



}