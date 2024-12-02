#include <bits/stdc++.h>
#define endl '\n'
#define lng long long

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

    std :: priority_queue<lng int, std :: vector<lng int>, std :: greater<lng int>> min;
    min.push(prefix[0]);
    lng int best = prefix[1] - prefix[0];
    for(int r = 0; r < n; r++){
        lng int sub = prefix[r+1] - min.top(); 
        if(best < sub){
            best = sub;
        }
        min.push(prefix[r + 1]);
    } 

    std :: cout << best;
}