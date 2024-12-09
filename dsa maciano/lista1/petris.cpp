#include <bits/stdc++.h>
#define endl '\n'
#define lng long long int

typedef struct Node{
    int val;
    Node *prev;
    Node *next;
} Node;

Node *create_node(){
    Node *node = new Node;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

typedef struct Stack{
    int size;
    Node *header;
    Node *top;
} Stack;

Stack *create_Stack(){
    Stack *newStack = new Stack;
    newStack->header = create_node();
    newStack->top = newStack->header;

    newStack->header->next = NULL;
    newStack->header->prev = NULL;
    
    newStack->size = 0;

    return newStack;
}

void Stack_insert(Stack *s, int val){
    Node *newtop = create_node();
    newtop->val = val;

    s->top->next = newtop;
    newtop->prev = s->top;
    s->top = newtop;
    s->size++;
}

void Stack_pop(Stack *s){
    if(s->top != s->header){
        s->top = s->top->prev;
        delete s->top->next;
        s->top->next = NULL;
        s->size--;
    }
}

typedef struct Node_l{
    Stack *s;
    struct Node_l *next;
    struct Node_l *prev;
} Node_l;

Node_l *create_nodel(){
    Node_l* newnode = new Node_l;
    newnode->s = create_Stack();
    newnode->prev = NULL;
    newnode-> next = NULL;
    return newnode;
}

typedef struct List{
    int size;
    Node_l *header;
} List;

List *create_list(){
    List *newlist = new List;
    newlist->header = create_nodel();
    newlist->size = 0;
    return newlist;
}

void List_insert_right(List *l, int val){
    Node_l *newnode = create_nodel();
    Stack_insert(newnode->s, val);
    Node_l* start = l->header;
    while(start->next){
        start = start->next;
    }
    start->next = newnode;
    newnode->prev = start;
    l->size++;
}

void List_insert_left(List *l, int val){
    Node_l *newnode = create_nodel();
    Stack_insert(newnode->s, val);
    Node_l* start = l->header;
    
    l->header->next->prev = newnode;
    newnode->next = l->header->next;
    newnode->prev = l->header;
    l->header->next = newnode;
    l->size++;
}

void List_remove(List *l, Node_l *n){
    n->prev->next = n->next;
    if(n->next){
        n->next->prev = n->prev;
    }
    delete n;

    l->size--;
}


int main(){
    std :: ios_base::sync_with_stdio(false);
    std :: cin.tie(0);

    int p;
    std :: cin  >> p;
    for(int k = 0; k < p; k++){
        List *l = create_list();
        std :: string first;
        do{
            std :: cin >> first;
            if(first != "END"){
                int sta = stoi(first);
                int col;

                std :: cin >> col;
                if(sta == 0){
                    List_insert_left(l, col);
                }
                else if(sta > l->size){
                    List_insert_right(l, col);
                }
                else{
                    Node_l *start = l->header;
                    int count = 0;
                    while(start->next and count != sta){
                        start = start->next;
                        count++;
                    }
                    Stack_insert(start->s, col);
                    if(start->s->size > 1 and start->s->top->val == start->s->top->prev->val){
                        Stack_pop(start->s);
                        Stack_pop(start->s);
                        if(start->s->size == 0){
                            List_remove(l, start);
                        }
                    }
                    
                }
            }

        }while(first != "END");

        std :: cout << "caso " << k << ":";
        Node_l *start = l->header;
        while(start->next){
            start = start->next;
            std :: cout << " " << start->s->top->val;
        }
        std :: cout << endl;

    }
}