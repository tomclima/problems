/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, k; cin >> n >> k;

    priority_queue<ll> left;
    priority_queue<ll> right;

    // push negative vals to create minheap
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        right.push(-val);
    }
    for(int i = 0; i < n; i++){
        ll val; cin >> val;
        left.push(-val);
    }

    ll last_right;
    ll last_left;
    ll cnt = 0;
    while(k >= 0 and right.size() > 0 and left.size() > 0){
        cnt++;
        last_right = right.top();
        last_left = left.top();
        k += right.top() + left.top();
        right.pop();
        left.pop();
    }
    if(k < 0) cnt--;
    cout << cnt;



}