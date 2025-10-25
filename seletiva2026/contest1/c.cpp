/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr;
        for(int i = 0; i < n; i++){
            int a; cin >> a;
            arr.push_back(a);
        }

        for(int i = 0; i < n; i++){
            int allxor = 0;
            int val = arr[i];
            for(int j = 0; j < n; j++){
                if(j != i){
                    allxor ^= arr[j];
                }
            }
            if(allxor == val){
                cout << allxor << endl;
                break;
            }
        }
    }
}