#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int tc = 0; tc < t; tc++){
        string n;
        cin >> n;
        priority_queue<lng> subs;
        map<lng, lng> losses;
        for(int i = 0; i < n.length(); i++){
            subs.push((int)((n[i]) - i - '0'));
            losses.insert(make_pair(n[i] - i - '0', i));
        }
        string m;
        for(int i = 0; i < n.length(); i++){
            m.push_back(min(subs.top() + i, subs.top() + losses[subs.top()]) + '0');
            subs.pop();
        }
        cout << m << endl;
    }
}