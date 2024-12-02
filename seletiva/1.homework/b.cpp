#include <bits/stdc++.h>
using namespace std;

typedef struct Node{
    char val;
    struct Node *next;
    struct node *prev;
}Node;

Node *create_node(){
    Node *node = new Node;
    return node;
}

typedef struct List{
    struct Node *header;
}List;

List* create_List(){
    List *list = new List;
    return list;
}

void List_insert(List *list, char val){
    Node *node = create_node();
    node->val = val;

    Node *iter = list->header;
    while(iter->next != NULL){
        iter = iter->next;
    } 
    iter->next = node;
}

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;   

    int n = s.size();

    for(int i = 0; i < n; i++){
        
    }
    
}