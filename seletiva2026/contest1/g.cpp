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
            int val;
            cin >> val;
            arr.push_back(val);
        }

        reverse(arr.begin(), arr.end());

        vector<int> ans;
        ans.push_back(arr.back());
        arr.pop_back();

        int count_ans = 0;
        while(arr.size() > 0){
            
            if(arr.back() <= 2*(ans.back()) and ans.back() <= 2*(arr.back())){
                ans.push_back(arr.back());
                arr.pop_back();
            }
            
            else if(arr.back() > 2*(ans.back())){
                ans.push_back(2*ans.back());
                count_ans++;
            }

            else if(ans.back() > 2*(arr.back())){
                ans.push_back(ceil((float)ans.back()/2));
                count_ans++;
            }

        }

        cout << count_ans << endl;
    }


}