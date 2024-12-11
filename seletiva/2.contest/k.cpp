#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<lng> g;
        vector<lng> pre_even;
        lng sum_even = 0;
        lng sum_odd = 0;
        vector<lng> pre_odd;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            g.push_back(x);
            if(i % 2 == 0){
                sum_even += x;
            }
            else{
                sum_odd += x;
            }
            pre_even.push_back(sum_even);
            pre_odd.push_back(sum_odd);
        }

        int l = 0;
        set<lng> 
        for(int r = 0; r < n; r++){
            
        }

    }   
}