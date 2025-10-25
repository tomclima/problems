#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n, q;
        cin >> n >> q;
        vector<int> c;
        while(n--){
            int a;
            cin >> a;
            c.push_back(a);

        }
   
        sort(c.rbegin(), c.rend());
        vector<lng> prefix;
        lng sum = 0;
        for(int i = 0; i < c.size(); i++){
            prefix.push_back(sum);
           // cout << sum << " ";
            sum += c[i];
        }
        prefix.push_back(sum);
        // cout << endl;

        while(q--){
            int x;
            cin >> x;
            // cout << x << endl;

            int left = 0;
            int right = prefix.size() - 1;
            int answer = -1;
            while(left <= right){
                int mid = left + (right - left)/2;

                if(prefix[mid] < x){
                    left = mid + 1;
                }
                else{
                    answer = mid;
                    right = mid -1;
                }
            }
            if(answer == -1){
                answer = left + (right - left)/2;
            }

            if(answer >= prefix.size()){
                answer = -1;
            }

            cout << answer << endl;
        }
    }
}