#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        arr.push_back(i+1);
    }

    if(n < 5){
        cout << "NO SOLUTION";
    }

    else{
        for(int i = 0; i < n/2; i++){
            arr[i] = 2 + 2*i
        }
        for(int i = 0; i < (n - n/2); i++){
            arr[i+n/2] = 1 + 2*i; 
        }
    }

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}