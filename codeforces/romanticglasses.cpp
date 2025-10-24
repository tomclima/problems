/*link*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; 
    cin >> t;

    while(t--){
        
        vector<ll> even(1, 0);
        vector<ll> odd(1, 0);
        vector<ll> diff(1, 0);

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            int val;
            cin >> val;
            even.push_back(even[i-1] + val*(i%2 == 0)); // prefix sum of even
            odd.push_back(odd[i-1] + val*(i%2 == 1)); // prefix sum of odd
            diff.push_back(odd[i] - even[i]);
        }

        map<ll, int> diff_index;
        int found = false;
        for(int i = 0; i < diff.size(); i++){
            if(diff_index[diff[i]] > 0){
                found = true;
                break;
            }
            diff_index[diff[i]]++;
        }

        if (found){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }







    }
}