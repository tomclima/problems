#include <iostream>
using namespace std;

#define INF 999999


typedef struct Edge{

    int from = -1;
    int to = -1;
    int weight = -1; 

} Edge;

Edge *create_edge(int from, int to, int weight){
    
    Edge *newedge = new Edge;
    
    newedge->from = from;
    newedge->to = to;
    newedge->weight = weight;

    return newedge;
}

void swap(Edge *arr[], int i, int j){
    
    Edge *temp = arr[i];
    
    arr[i] = arr[j];
    arr[j] = temp;

}

void heap_insert(Edge *heap[], int &size, int from, int to, int weight){

    int index = size+1; // insert at end of heap;
    heap[index] = create_edge(from, to, weight);
    size++;

    if(index = 1) return; // if heap was empty before;

    while(index > 1 and heap[index]->weight < heap[index/2]->weight){
        
        swap(heap, index, index/2);
        index = index/2;

    }

}

void heap_removemin(Edge **heap, int &size){
    
    swap(heap, 1, size);

    delete heap[size];
    heap[size] = NULL;

    size--;

    bool isheap = false;
    int k = 1;
    Edge* v = heap[k];
    while(!isheap and (2 * k < size)){
        
        int j = 2 * k;
        if(j < size and heap[j]->weight < heap[j + 1]->weight){
            j++;
        }

        if(v->weight >= heap[j]->weight){
            isheap = true;
        }

        else{
            heap[k] = heap[j];
            k = j;
        }
    }

    heap[k] = v;

}


int next_adj(int *graph[], int size, int i, int j){
    
    while(j+1 < size){
        
        if(graph[i][j+1] != -1) return j+1;
        j++;
    }

    return size;
}

int first_adj(int *graph[], int size, int i){
    return next_adj(graph, size, i, -1);
}

void Primm(int *graph[], int graph_size, int d[], int parent[]){

    bool visited[graph_size];
    for(int i = 0; i < graph_size; i++){
    
        d[i] = INF;
        parent[i] = -1;
        visited[i] = false;

    }
    
    Edge **heap = new Edge*[graph_size];
    int heap_size = 0;
    d[0] = 0;

    heap_insert(heap, heap_size, 0, 0, 0);
    for(int i = 0; i < graph_size-1; i++){

        int p, v, cost;
        do{
            
            Edge *curr = heap[1];
            if(curr == NULL) return;
            
            p = heap[1]->from;
            v = heap[1]->to;
            cost = heap[1]->weight;

            heap_removemin(heap, heap_size);

            cout << "removed" << p << " " << v << " " << cost << endl;

        }while (visited[v] == true);

        visited[v] = true;
        parent[v] = p;
        
        int w = first_adj(graph, graph_size, v);
        while(w < graph_size){
            
            if(visited[w] == false and d[w] > graph[v][w]){
                
                d[w] = graph[v][w];
                heap_insert(heap, heap_size, v, w, graph[v][w]);


            }

            w = next_adj(graph, graph_size, v, w);

        }

    }
}

int main(){
    
    int graph_size, n;
    cin >> graph_size >> n;

    int **graph = new int*[graph_size];
    for(int i = 0; i < graph_size; i++){
        graph[i] = new int[graph_size];
    }

    // no edges at first
    for(int i  = 0; i < graph_size; i++){

        for(int j = 0; j < graph_size; j++){

            graph[i][j] = -1;

        }
    }

    // filling weighted edges
    int total = 0;
    for(int i = 0; i < n; i++){

        int v, u, p;
        cin >> v >> u >> p;

        graph[v][u] = p;
        graph[u][v] = p;
        total += p;

    }


    // primm
    int d[graph_size];
    bool visited[graph_size];
    int parent[graph_size];

    Primm(graph, graph_size, d, parent);

    for(int i = 0; i < graph_size; i++){
        total -= graph[i][parent[i]];
    }

    cout << total << endl;
}