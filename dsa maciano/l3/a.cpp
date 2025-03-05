/*https://iudex.io/problem/6058d77151aa87000155c76f/statement*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

#include <iostream>

template <typename T>
class Node{
    public:
        T data;
        Node *next;

        // constructor
        Node(const T &val) : data(val), next(NULL) {}  
};

template <typename T>
class List{
    public:
        Node<T>* head;
    
        int size = 0;
        // constructor
        List() : head(new Node(-9999999)) {}

        void push_back(int val){
            Node<T> *newnode = new Node(val);
            newnode->next = head->next;
            head->next = newnode;
            size++;
        }

        Node<T> *first(){
            return head->next;
        }
};



vector<int> visited;
void dfs(vector<List<int>> &g, int s){

    visited[s] = true;
    cout << s << " ";
    
    Node<int> *next = g[s].first();
    while(next){
        if(!visited[next->data]){
            dfs(g, next->data);
        }
        next = next->next;
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<List<int>> graph;
    int n;
    cin >> n;
    
    graph.resize(n);
    
    int v1, v2, k;
    do{
        cin >> v1 >> v2 >> k;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }while(k != 0);
    
    
    for(int i = 0; i < n; i++){
        cout << i << ": ";
        Node<int> *curr = graph[i].first();
        
        if(curr == NULL) cout << "Lista Vazia";
        
        while(curr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    cout << endl;
    
    
    visited.resize(n);
    dfs(graph, 0);


    
}