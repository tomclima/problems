#include <bits/stdc++.h>
#define endl '\n'
#define lng long long
#define heap priority_queue

int main(){
    std :: ios_base::sync_with_stdio(false);
    int n;
    std :: cin >> n;

    std :: vector<lng int> arr;
    std :: vector<lng int> prefix;
    lng int sum = 0;
    for(int i = 0; i < n; i++){
        prefix.push_back(sum);
        lng int x;
        std :: cin >> x;
        sum += x;
        arr.push_back(x);
    }
    prefix.push_back(sum);

    int min;
    min = prefix[0];
    lng int best = prefix[1] - prefix[0];
    for(int r = 0; r < n; r++){
        lng int sub = prefix[r+1] - min; 
        if(best < sub){
            best = sub;
        }
        if(prefix[r+1] < min){
            min = prefix[r+1];
        };
    } 

    std :: cout << best;
}