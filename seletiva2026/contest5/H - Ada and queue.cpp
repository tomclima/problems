/*link*/

#include <bits/stdc++.h>
using namespace std;
//#define endl '\n'
#define ll long long int
#define MAXN 1000000000000000000

void print_failure(){
    cout << "No job for Ada?" << endl;
}

int solve(){
    int n; cin >> n;
    deque<int> queue;
    bool reversed = false;
    while(n--){
        string query; cin >> query;
        if(query == "back" and !reversed or query == "front" and reversed){
            if(queue.empty()) print_failure();
            else{
                int val = queue.back(); queue.pop_back();
                cout << val << endl;
            }
        }
        else if(query == "front" and !reversed or query == "back" and reversed){
            if(queue.empty()) print_failure();
            else{
                int val = queue.front(); queue.pop_front();
                cout << val << endl;
            }
        }
        else if(query == "reverse"){
            reversed = !reversed;
        }
        else if (query == "push_back" and !reversed or query == "toFront" and reversed){
            int k; cin >> k;
            queue.push_back(k);
        }
        else{
            int k; cin >> k;
            queue.push_front(k);
        }

    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; // cin >> t;
    while(t--){
        solve();
    }
}