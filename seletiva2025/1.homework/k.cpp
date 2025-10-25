#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<lng> hist;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        hist.push_back(x);
    }
    
    multiset<lng> minh;
    lng best = 0;
    lng l = 0;
    for(lng r = 0; r < n; r++){
        minh.insert(hist[r]);
        while(l < r and *minh.begin() < r - l + 1){
            minh.erase(hist[l]);
            l++;
        }   
        if(min(*minh.begin(), r - l + 1) > best){
            best = min(*minh.begin(), r - l + 1);
        }
    }

    cout << best;
}