#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<lng> times;
    times.reserve(3);

    lng total_sum = 0;
    for(int i = 0; i < 3; i++){
        cin >> times[i];
        total_sum += times[i];
    }
    priority_queue<lng, vector<lng>, greater<lng>> minheap;
    for(int i = 0; i < 3; i++){
        minheap.push(total_sum - times[i]);
    }

    cout << minheap.top();
}