#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

#define inf 1000001
 
bool compare(vector<int> a, vector<int> b){
    if(a[2] < b[2]){
        return true;
    }
    else{
        return false;
    }
}

int next(vector<int> v, int i){
    while(i + 1 < v.size() and v[i+1] == 0){
        i++;
    }
    return i+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        int n;
        cin >> n;

        vector<vector<int>> graph;
        int numedge = 0;
        graph.resize(n);
        for(int i = 0; i < n; i++){
            graph[i].resize(n);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int d;
                cin >> d;
                graph[i][j] = d;
                if(d > 0) {
                    numedge++;
                }
            }
        }
        int r;
        cin >> r;
        lng total = 0;
        while (r--){
            int source, dest;
            cin >> source >> dest;
            

            vector<int> mark;
            mark.resize(n);
            vector<int> distance;
            distance.resize(n);
            vector<int> parent;
            parent.resize(n);
            priority_queue<vector<int>, vector<vector<int>>, mycomp> h;

            vector<int> self;
            self.resize(3);
            self[0] = source;
            self[1] = source;
            self[2] = 0;

            for(int i = 0; i < n; i++){
                distance[i] = inf;
                parent[i] = -1;
                mark[i] = 0;
            }
            h.push(self);
            distance[source] = 0;

            for(int i = 0; i < n; i++){
                int p, v;
                p = -1; v = -1;
                do{
                    p = h.top()[0];
                    v = h.top()[1];
                    h.pop();
                }while(mark[v] == 0);
                mark[v] = 1;
                parent[v] = p;
                int w = next(graph[v], -1); // first edge
                while(w < n){
                    if(mark[w] != 1 and distance[w] > distance[v] + graph[v][w]){
                        distance[w] = distance[v] + graph[v][w];
                        vector<int> trip;
                        trip.resize(3);
                        trip[0] = v; trip[1] = w; trip[2] = distance[w];
                        h.push(trip);
                    }
                    w = next(graph[v], w);
                }
            }

            total += distance[dest];
        }

        cout << "Case #" << tc + 1 << ' ' << total << endl;  
    }
}