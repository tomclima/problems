#include <bits/stdc++.h>
using namespace std;



int main(){
    long long int n;
    cin >> n;
    vector<long long int> arr;

    if (n == 1){
        cout << "1";

    }
    else if(n < 4){
        cout << "NO SOLUTION";
    }

    else{
        for(int i = 0; i < n/2; i++){
            arr.push_back(2 + 2*i);
        }
        for(int i = 0; i < (n - n/2); i++){
            arr.push_back(1 + 2*i); 
        }
    }

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
}