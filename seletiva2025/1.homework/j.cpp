#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    
    deque<int> q;
    
    bool reverse = false;
    for(int i = 0; i < n; i++){
        string cmd;
        int val;
        cin >> cmd;

        if(cmd == "toFront"){
            cin >> val;
            if(!reverse){
                q.push_front(val);
            }
            else{
                q.push_back(val);
            }
        }
        else if(cmd == "push_back"){
            cin >> val;
            if(!reverse){
                q.push_back(val);
            }
            else{
                q.push_front(val);
            }
        }
        else if(cmd == "reverse"){
            reverse = not reverse;
        }
        else if (q.empty()){
            cout << "No job for Ada?" << endl;
        }
        else if(cmd == "back"){
                if(reverse){
                    cout << q.front() << endl;
                    q.pop_front();
                }
                else{
                    cout << q.back() << endl;
                    q.pop_back();
                }
        }
        else if(cmd == "front"){
            if(reverse){
                cout << q.back() << endl;
                q.pop_back();
            }
            else{
                cout << q.front() << endl;
                q.pop_front();
            }
        }


    }
}