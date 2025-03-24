#include <iostream>
using namespace std;


struct no{ //node lista
    
    int val;
    int peso;
    no* prox;
    
};

struct lista{
    
    no* header;

};



lista* cria_lista(){
    
    lista* lis = new lista();
    lis->header = nullptr;
    
    
    return lis;
    
}

no* cria_no(int num, int p){
    
    no* el = new no();
    el -> val = num;
    el -> peso = p;
    el -> prox = nullptr;
    
    return el;
}


void inserir(lista* lis, int num, int pes){
    
    no* el = new no();
    el -> val = num;
    el -> peso = pes;
    if (lis -> header != nullptr){
        
        el -> prox = lis -> header;
        lis -> header = el;
        
        
    }
    else{
        
        lis -> header = el;
        el -> prox = nullptr;
        
    }
}



no* busca(lista* lis, int x){
    
    no* y;
    y = lis->header;
    
    while (y != nullptr and y->val != x){
        
        y = y -> prox;
        
        
    }
    
    return y;
    
    
    
}


struct node { //node avl
    int valor, altura;
    node *esquerda, *direita;
    node(int val) {
        valor = val;
        altura = 1;
        esquerda = nullptr;
        direita = nullptr;
    }
};

struct AVL {
    node* raiz;
    int total;
    AVL() {
        raiz = nullptr;
        total = 0;
    }
};

int altura(node* n) {
    if (n == nullptr) {
        return 0;
    }
    return n->altura;
}



void atualizar(node* n) {
    if (n != nullptr) {
        n->altura = 1 + max(altura(n->esquerda), altura(n->direita));
    }
}

node* rotacaoDireita(node* y) {
    node* x = y->esquerda;
    y->esquerda = x->direita;
    x->direita = y;
    atualizar(y);
    atualizar(x);
    return x;
}

node* rotacaoEsquerda(node* x) {
    node* y = x->direita;
    x->direita = y->esquerda;
    y->esquerda = x;
    atualizar(x);
    atualizar(y);
    return y;
}

int fatorBalanceamento(node* n) {
    
    return altura(n->esquerda) - altura(n->direita);
}

node* inserir_aux(node* nd, int val) {
    
    if (nd == nullptr) {
        return new node(val);
    }

    if (val < nd->valor) {
        nd->esquerda = inserir_aux(nd->esquerda, val);
    } else if (val > nd->valor) {
        nd->direita = inserir_aux(nd->direita, val);
    }
    
    atualizar(nd);
    int fb = fatorBalanceamento(nd);
    if (fb > 1 && val < nd->esquerda->valor) {
        return rotacaoDireita(nd);
    }
    if (fb < -1 && val > nd->direita->valor) {
        return rotacaoEsquerda(nd);
    }
    if (fb > 1 && val > nd->esquerda->valor) {
        nd->esquerda = rotacaoEsquerda(nd->esquerda);
        return rotacaoDireita(nd);
    }
    if (fb < -1 && val < nd->direita->valor) {
        nd->direita = rotacaoDireita(nd->direita);
        return rotacaoEsquerda(nd);
    }
    return nd;
}

void inserir(AVL* a, int val) {
    
    a->raiz = inserir_aux(a->raiz, val);
}

node* buscar(node* node, int val) {
    
    while (node != nullptr) {
        if (val < node->valor) {
            node = node->esquerda;
        } else if (val > node->valor) {
            node = node->direita;
        } else {
            return node;
        }
    }
    return nullptr;
}


struct min_heap {
    
    int tam_heap;
    int *arr;
    
    
};

void min_heapify(min_heap *heap, int p[], int i, int tam_heap){
    
    int l, r;
    l = 2*i;
    r = 2*i + 1;
    
    int menor;
    
    if (l <= tam_heap and p[heap->arr[l]] < p[heap->arr[i]]){
        
        menor = l;
        
    }
    
    else{
        
        menor = i;
        
    }
    
    
    if (r <= tam_heap and p[heap->arr[r]] < p[heap->arr[menor]]){
        
        
        menor = r;
        
    }
    
    
    if (menor != i){
        
        int temp;
        
        temp = heap->arr[i];
        heap->arr[i] = heap->arr[menor];
        heap->arr[menor] = temp;
        
        min_heapify(heap, p, menor, tam_heap);
    }
    
}


min_heap* nova_heap(int comprimento, int p[]){
    
    min_heap* heap = new min_heap();
    
    heap->arr = new int [comprimento + 1];
    heap->tam_heap = comprimento;
    
    for (int j = 0; j <= comprimento; j++){
        
        heap->arr[j] = j - 1;
        
        
    }
    

    for (int i = int(comprimento/2); i > 0; i--){
        
        min_heapify(heap, p, i, comprimento);
        
    }
    return heap;
    
}


int extrair_min (min_heap* heap, int p[]){
    
    int min;
    min = heap->arr[1];
    heap->arr[1] = heap->arr[heap->tam_heap];
    heap->tam_heap = heap->tam_heap - 1;
    
    min_heapify(heap, p, 1, heap->tam_heap);
    
    return min;
}


void heap_print(min_heap *heap, int p[]){
    
    for(int i = 1; i <= heap->tam_heap; i++){
        cout << i<< ":(" <<   heap->arr[i] << "," <<  p[heap->arr[i]] <<  ") ";
    }
    
    // for(int i = heap->tam_heap; i/2 > 0; i--){
    //     if(p[heap->arr[i]] < p[heap->arr[i/2]]) cout << "errada :(" << endl;
    // }
    
    
    
    cout << endl << endl;
    
}


void relaxar(lista* grafo[], int pesos_vert[], int ant[], int u, int v){ // u e v são os vértices
    
    int w;
    w = busca(grafo[u], v)->peso;
    
    if (pesos_vert[v] > pesos_vert[u] + w){
        
        ant[v] = u;
        
        pesos_vert[v] = pesos_vert[u] + w;
        
        
    }
    
    
}






int dijkstra(lista* grafo[], int origem, int dest, int qnt_v){
    
    int p [qnt_v];
    int ant [qnt_v];

    
    for (int i = 0; i < qnt_v; i++){
        
        p[i] = 99999;       // "infinito", dados os limites da questão
        ant[i] = -1;
        
    }
    
    p[origem] = 0;
    AVL* sol = new AVL();
    
    min_heap* heap = nova_heap(qnt_v, p);
    
    while(heap->tam_heap != 0){
        
        for (int i = int(heap->tam_heap/2); i > 0; i--){
        
            min_heapify(heap, p, i, heap->tam_heap);
        
        }
        
        heap_print(heap, p);
        
        int u;
        u = extrair_min(heap, p);
        inserir(sol, u);
        
        no* vert_adj;
        vert_adj = grafo[u]->header;
        
        
    
        while(vert_adj != nullptr){
            
            relaxar(grafo, p, ant, u, vert_adj->val);
            
            vert_adj = vert_adj->prox;
            
        }
        
        
    }
    
    return p[dest];
    
}







int main()
{
    int q, r, n;
    cin >> q >> r >> n;
    
    lista* grafo[q];
    
    for (int i = 0; i < q; i++){
        
        grafo[i] = cria_lista();
        
    }
    
    for (int i = 0; i < r; i++){
        
        int a, b, m;
        cin >> a >> b >> m;
        
        inserir(grafo[a], b, m);
        
    }
    
    
    int counter = 0;
    for (int i = 0; i < n; i++){
        
        int x;
        cin >> x;
        
        if (x == 1){ // nova aresta
            
            int a, b, m;
            cin >> a >> b >> m;
            
        }
        
        
        if (x == 2){ //menor tempo
            
            int a, b;
            cin >> a >> b;
            
            counter++;

            cout << counter << endl;
            if(counter == 60){
                cout << "hehe" << endl;
            }
            int valor;
            valor = dijkstra(grafo, a, b, q);
            
            
            if (valor != 99999){
                
                //cout << valor << endl;
                
                
            }
            else{
                
                //cout << -1 << endl;
                
            }
        }
        
    } 

    return 0;
}