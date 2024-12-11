#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lng long long int

lng fun(vector<lng> &chor, lng h){
    lng sum = 0;
    for(int i = 0; i < chor.size(); i++){
        sum += max(h - chor[i], (lng)0);
    }

    return sum;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        lng n, x;
        cin >> n >> x;

        vector<lng> chor;
        for(int i = 0; i < n; i++){
            lng a;
            cin >> a;
            chor.push_back(a);
        }
        sort(chor.begin(), chor.end());


        lng l = chor[0];
        lng r = chor[0] + x;
        lng answer = -1;
        
        while(l <= r){
            lng mid = l + (r - l)/2;

            if(fun(chor, mid) <= x){
                l = mid + 1;
            }
            else{
                answer = mid;
                r = mid - 1;
            }
        }
        if(answer == -1){
            answer = l + (r - l)/2;
        }



        cout << answer - 1 << endl;

    }
}