#include <bits/stdc++.h>
using namespace std;



int main(){
    long long int n;
    cin >> n;
    vector<long long int> arr;

    for (int i = 1; 2*i <= n; i++){
        arr.push_back(2 * i);
    }
    for (int i = 0; 2*i + 1 <= n; i++){
        arr.push_back(2*i + 1);
    }

    if(n == 3 or n == 2) cout << "NO SOLUTION";
    else{
        for (int i = 0; i < n-1; i++){
            cout << arr[i] << " ";
        }
        cout << arr.back();
    }
}