#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

        long long int n;
        cin >> n;
        long long int modulo = pow(10, 9) + 7;
        long long int answer;

        vector<long long int> first_six = {1, 2, 4, 8, 16, 32};
        deque<long long int> last_six;
        long long int sum = 0;

        for(int i = 0; i < 6; i++){
            last_six.push_back(first_six[i]);
            sum += first_six[i] % modulo;
        }
        
        for(int i = 0; i < n - 6; i++){
            last_six.push_back(sum);
            sum = (2 * sum - last_six[0]) % modulo;
            last_six.pop_front();
        }

        if(n < 6){
            answer = first_six[n-1];
        }
        else{
            answer = last_six.back();
        }
        
        cout << answer % modulo;
}