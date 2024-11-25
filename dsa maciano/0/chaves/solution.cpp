#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    getline(cin, a);
    bool improper = false;
    vector<int> stack;

    for(int i = 0; i < a.size(); i++){
        if(a[i] == '{'){
            stack.push_back(a[i]);
        }
    }

    for(int i = 0; i < a.size(); i++){
        if(a[i] == '}'){
           if(stack.empty()){
            improper = true;
            break;
           }
           else{
            stack.pop_back();
           }
        }
    }

    if(!stack.empty()){
        improper = true;
    }

    if(improper){
        cout << "N" << endl;
    }
    else{
        cout << "S" << endl;
    }
}

