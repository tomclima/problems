/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 999999999
#define lng long long int
#define p_queue priority_queue<pair<State, lng>, vector<pair<State, lng>>, Custom_comp>

typedef tuple<int, int, int, int> State;

class cmap {
    private:
        std::map<State, lng> myMap;
    public:
        lng& operator[](State key) {
            if (myMap.find(key) == myMap.end()) {
                myMap[key] = INF;  // Custom default value
            }
            return myMap[key];
        }
    };

class Custom_comp{
    public:
        bool operator()(const pair<State, lng> &a, const pair<State, lng> &b){
            return a.second > b.second;
        }
};

bool get_mark(State state, set<State> visited){
    if(visited.find(state) != visited.end()) return true;
    else return false;

}

void relax(State a, State b, int w, cmap &cost, p_queue &heap){
    if(cost[a] > cost[b] + w){
        cost[a] = cost[b] + w;
        heap.push({b, cost[b]});
    }
}

vector<int> dn1 = {-8, -3, +2, +2};
vector<int> dn5 = {0, -1, -2, 0};
vector<int> dn10 = {0, 0, 0, -1};
vector<int> w_v = {8, 4, 2, 1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        
        int c, n1, n5, n10;
        cin >> c >> n1 >> n5 >> n10;

        cmap cost;
        map<State, bool> visited;

        p_queue heap;
        heap.push({{n1, n5, n10, 0}, 0});

        State state;

        while(!heap.empty()){
            
            state = heap.top().first;
            heap.pop();
            if(visited[state]) continue;
            
            int c_n1, c_n5, c_n10, c_c;

            c_n1 =             get<0>(state);
            c_n5 =             get<1>(state);
            c_n10 =         get<2>(state);
            c_c =    get<3>(state);

            if(c_c == c) continue;

            // state transitions

            int new_c;
            new_c = c + 1;
            
            for(int i = 0; i < 3; i++){
               
                int new_n1 = n1 + dn1[i];
                int new_n5 = n5 + dn5[i];
                int new_n10 = n10 + dn10[i];
                
                int w = w_v[i];
                
                

                State trans = {new_n1, new_n5, new_n10, new_c};
                relax(state, trans, w, cost, heap);

            }
            
            
        }

        
        cout << cost[state] << endl;
    }


}