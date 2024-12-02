#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
        int n;
        cin >> n;
        vector<int> arr;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            arr.push_back(x);
        }

        sort(arr.begin(), arr.end());
        int cnt = 1;
        int curr = arr[0];
        for(int i = 0; i < n; i++){
            if(arr[i] != curr){
                cnt++;
                curr = arr[i];
            }
        }
        cout << cnt;

}