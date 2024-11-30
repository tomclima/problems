#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    long long int n, k;
    cin >> n >> k;

    vector<int> arr;

    for(int i = 0; i < n; i++){
        long long unsigned int num;
        cin >> num;
        arr.push_back(num);
    }

    long long int count = 0;
    long long int sum = 0;
    long long int j = -1;
    for(int i = 0; i < n; i++){
        while(sum < k and j < n){
            j++;
            sum += arr[j];
        }
        if(j <= n){
            count += n - j;
            sum -= arr[i];
        }
        else{
            break;
        }   
    }

    cout << count;
}