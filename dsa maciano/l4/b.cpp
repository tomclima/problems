#include <iostream>
#include <stdlib.h> 
using namespace std;
#define endl "\n";

#define INF 999999
#define ADICAO 1
#define BUSCA 2



void heap_print(int heap[], int d[], int heap_size){
    for(int i = 1; i < heap_size; i++){
        cout << i<< ":(" <<   heap[i] << "," <<  d[heap[i]] <<  ") ";
    }
    cout << endl;
    cout << endl;
}

void heap_botup(int heap[], int size, int d[]){
    for(int i = size/2; i > 0; i--){
        
        bool isheap = false;
        int k = i;
        int v = heap[k];
        while(!isheap and (2 * k <= size)){
            
            int j = 2 * k;
            if(j < size and d[heap[j]] > d[heap[j + 1]]){
                j++;
            }

            if(d[v] <= d[heap[j]]){
                isheap = true;
            }

            else{
                heap[k] = heap[j];
                k = j;
            }
        }

        heap[k] = v;
    
    }
}

void heap_insert(int heap[], int &size, int vertice, int d[]){

    int index = size+1; // insert at end of heap;
    heap[index] = vertice;
    size++;

    if(index == 1) return; // if heap was empty before;

    int v = vertice;
    while(index > 1 and d[v] < d[heap[index/2]]){
        
        heap[index] = heap[index/2];
        index = index/2;
    }
    heap[index] = v;

}

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void heap_removemin(int heap[], int &size, int d[]){
    
    swap(heap, 1, size);

    heap[size] = -1;

    size--;

    bool isheap = false;
    int k = 1;
    int v = heap[k];
    while(!isheap and (2 * k <= size)){
        
        int j = 2 * k;
        if(j < size and d[heap[j]] > d[heap[j + 1]]){
            j++;
        }

        if(d[v] <= d[heap[j]]){
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


void relaxar(int *graph[], int u, int v, int d[], int parent[]){
    
    if(d[v] > d[u] + graph[u][v]){

        parent[v] = u;
        d[v] = d[u] + graph[u][v];

    }
}


void dijkstra(int **graph, int graph_size, int s, int d[], int parent[]){
    for(int i = 0; i < graph_size; i++){
        
        d[i] = INF;
        parent[i] = -1;
        
    }
    
    d[s] = 0;
    
    
    // heap creation and filling with vertices
    int heap[graph_size + 1];
    int heap_size = 0;
    for(int i = 0; i < graph_size; i++){
        heap_insert(heap, heap_size, i, d);
    }

    while(heap_size != 0){
        heap_botup(heap, heap_size, d);
        heap_print(heap, d, heap_size);

        int u = heap[1]; // min distance

        heap_removemin(heap, heap_size, d); // remove mindistance
        

        // iterates over all vertices adjacent to u
        int w = first_adj(graph, graph_size, u);
        while(w < graph_size){
            relaxar(graph, u, w, d, parent);
            w = next_adj(graph, graph_size, u, w);
        }
    }


}

int main(){

    int graph_size, r, n;
    cin >> graph_size >> r >> n;

    int **graph = new int*[graph_size];
    for(int i = 0; i < graph_size; i++){
        graph[i] = new int[graph_size];
    }

    for(int i  = 0; i < graph_size; i++){ // no edges at first

        for(int j = 0; j < graph_size; j++){
            graph[i][j] = -1;
        }
    }

    // filling weighted edges
    for(int i = 0; i < r; i++){

        int v, u, p;
        cin >> v >> u >> p;

        graph[v][u] = p;

    }



    for(int i = 0; i < n; i++){
        
        int consult_type;
        cin >> consult_type;

        if(consult_type == ADICAO){

            int v, u, p;
            cin >> v >> u >> p;
    
            graph[v][u] = p;

        }

        else if(consult_type == BUSCA){
            int v, u;
            cin >> v >> u;
            
            int d[graph_size];
            int parent[graph_size];
            dijkstra(graph, graph_size, v, d, parent);
            // delete[] parent;
            
            if(d[u] == INF) d[u] = -1;
            cout << d[u] << endl;
            // delete[] d;

        }
    }

}