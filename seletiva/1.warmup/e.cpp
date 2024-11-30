#include <bits/stdc++.h>
using namespace std;

int main(){
    long int n; // SEMPRE USAR LONG INT FODASE
    cin >> n;
    vector <long int> arr;
    long int moves = 0;

    for(int i = 0; i < n; i++){
        long int x;
        cin >> x;
        arr.push_back(x);
    }

    for(int i = 0; i < arr.size() -1; i++){
        long int diff = arr[i] - arr[i+1];
        if (diff > 0){
            arr[i + 1] += diff;
            moves += diff;
        }
    }

    cout << moves;
    return 0;
}
