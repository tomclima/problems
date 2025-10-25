#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    long long int n;
    cin >> n;

    vector <long long int> arr;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int i = arr.size() -1;
    while(arr[i] == arr[i-1]){
        i--;
    }
    cout << arr[i-1];
}