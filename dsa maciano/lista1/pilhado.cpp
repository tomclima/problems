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
        s->top->prev->next = NULL;
        s->top = s->top->prev;
        s->size--;
    }
}

int main(){
    std :: ios_base::sync_with_stdio(false);
    std :: cin.tie(0);

    int tc;
    std :: cin >> tc;
    for(int k = 0; k < tc; k++){
        Stack *s = create_Stack();
        int x = -1;
        do{
            std :: cin >> x;
            if(x != 0){
                Stack_insert(s, x);
            }
            while(s->size > 1 and s->top->val % 2 == s->top->prev->val % 2){
                s->top->prev->val = abs(s->top->val - s->top->prev->val);
                Stack_pop(s);
            }
            while(s-> size > 0 and s->top->val == 0){
                Stack_pop(s);
            }
        } while(x != 0);

        if(s->size == 0){
            s->top->val = - 1;
        }
        std :: cout << "Pilha " << k+1 << ": " <<  s->size << " " << s->top->val << endl;
        std :: cin;
    }


}