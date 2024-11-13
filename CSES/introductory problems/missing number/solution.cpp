#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> incomplete_list;
    vector<int> complete_list;
    cin >> n;
    for(int i = 0; i < n; i++){
        complete_list.push_back(i + 1);
    }
    for(int i = 0; i < n - 1; i++){
        int number;
        cin >> number;
        incomplete_list.push_back(number);
    }
    
    sort(&incomplete_list[0], &incomplete_list[incomplete_list.size()]);

    int error = -1;
    for(int i = 0; i < incomplete_list.size(); i++){
        if(error < 0 && (incomplete_list[i] != complete_list[i])){
            error = complete_list[i];
        }

    }
    if (error < 0){
        error = complete_list.back();
    }
    
    cout << error;

}