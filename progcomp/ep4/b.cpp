#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<int,int> number;
    int n;
    cin >> n;
    int answer = 1;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x > 0){
            if(number[x] == 0){
                answer++;
            }
            number[x] += 1;
        }
    }
    cout << answer;
}